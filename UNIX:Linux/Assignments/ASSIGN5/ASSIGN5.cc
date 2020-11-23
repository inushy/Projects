/*
   Anushka Verma <Z1911937>
   Prof. Lehuta
   CSCI 330 Section - 1
   assign05 - Using fork, pipes, and dup system calls. Grants insight into how the shell enables input and output redirection
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;

int main()
{
	char command1[255] = "command1", command2[255] = "command2"; //declared command1 and command2 as char

	char quit[] = "quit"; //declared quit as a char array which we can use to check against for the quit command

	while ((strcmp(command1,quit)!= 0) && (strcmp(command2,quit) !=0)) //if quit is not typed in command line
	{
		cout << "command1? ";
		cin.getline(command1, 255); //get user input
		if((strcmp(command1,quit)== 0))
		{
			return 0;
		}

		cout << "command2? ";
		cin.getline(command2, 255); //get user input
		if ((strcmp(command2,quit)== 0))
		{
			return 0;
		}

		//declared variables that are further used in the code
		int pipefd[2]; //defining what pipefd is
		int runsys = pipe(pipefd); //creating pipe

		char *par, *par2; //parsing the user input	
		char *ar[10], *ar2[10]; //parsing the command into the array
		int index = 1, count = 1; //variable for the command(s)

		//able to split the text entered by the user into the individual command line arguments that comprise it
		par = strtok(command1, " ");
		ar[0] = par;

		while (par != NULL) //continues from where it left off if our par isn't equal to 0
		{
			par = strtok(NULL," ");
			
			ar[index] = par;

			index++;
		}

		par2 = strtok(command2, " ");
		ar2[0] = par2;

		while (par2 != NULL) //continues from where it left off if our par isn't equal to 0
		{
			par2 = strtok(NULL, " ");
			
			ar2[count] = par2;

			count++;
		}

		if (runsys < 0) //if pipe fails
		{
			perror("Piping Failure!"); //print error message
			exit(EXIT_FAILURE); //exits the program
		}

		//fork has two process, parent and child
		//for the two processes to work, we need to create a fork
		runsys = fork();

		if (runsys < 0) //if fork fails
		{
			perror("Fork Failure!"); //print error message
			exit(EXIT_FAILURE); //exits the program
		}

		if (runsys == 0) //once fork is created, we child processes is created
		{
			close(pipefd[1]); //closed the output end of the pipe

			close(0); //close stdin

			dup(pipefd[0]); //duplicates the input end of the pipe to stdin

			close(pipefd[0]); //closed the input end of the pipe

			runsys = execvp(ar2[0], ar2); //run the second command

			if (runsys < 0) //checks to see if exec failed
			{
				perror("Execvp Failure!"); //prints error message
				exit(EXIT_FAILURE); //exits the program
			}
		}
		else
		{
			//to start the parent process, we need to create a new fork
			int runsys2 = fork();

			if (runsys2 == -1) //checking to see if our fork failed
			{
				perror("Fork Failure"); //prints error message
				exit(EXIT_FAILURE); //exits the program
			}

			if (runsys2 == 0) //if fork didn't fail, then we can start the child process
			{
				close(pipefd[0]); //closed the input end of the pipe

				close(1); //close stdout

				dup(pipefd[1]); //duplicates the output end of the pipe to stdout

				close(pipefd[1]); //closed the output end of the pipe

				runsys = execvp(ar[0], ar); //run the first command

				if (runsys == -1) //checks to see if exec failed
				{
					perror("Execvp Failure!"); //prints error message
					exit(EXIT_FAILURE); //exits the program
				}
			}
			else
			{
				//Time to finish it off with the parent process!
				//closes the input and the output ends of the pipes since we don't use them in the parent process
				close(pipefd[0]);
				close(pipefd[1]);

				//process to terminate
				wait(&runsys2);
				wait(&runsys);
			}
		}
	}
	return 0;
}
