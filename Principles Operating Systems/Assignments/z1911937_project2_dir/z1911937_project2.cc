/********************************************************************
CSCI 480 - Assignment 2 - Semester (Spring) 2022

Progammer: Anushka Verma
Section:   001
TA:        Mosab Rezaei
Date Due:  02/19/2022
Purpose:   This is a program that helps to serve as a shell interface 
           that accepts user commands and then executes each command 
           in a separate process.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>

#define MAX_LINE 1024

using namespace std;

bool forking(char *arg[])
{
    pid_t pid; //Process identification data type to declare a variable for the fork process
    pid = fork(); //pid_t variable used for the fork process

    if(pid < 0) //if fork fails
    {
        perror("Fork Failure!"); //print error message
        exit(EXIT_FAILURE); //exits the program
    }
    else if(pid == 0) //else, run the command
    {
        int completed = execvp(arg[0], arg);
        exit(0);
    }
    else
    {
        wait(NULL);
    }
    return false;
}

string getInput()
{
    string command1; //declared command1 as char
    cout << "mysh> ";
    getline(cin,command1); //get user input
    return command1;
}

int main(void)
{
    vector<string>history; //declaring a vector string
    while (true) 
    {
        string command1 = getInput();
        if(command1 == "quit" || command1 == "q") //if command1 equals "quit" or "q"
        {
            //then return 0
            return 0;
        }

        //history
        if(command1 == "!!") //if command1 equals "!!"
        {
            //if the history size equals 0
            if(history.size() == 0)
            {
                //then print error message
                cout << "No commands in history." << endl;
            }
            else //else, access the last element
            {
                command1 = history.back();
            }
        }
        //if command1 equals "history"
        if(command1 == "history")
        {
            //if the history size equals 0
            if(history.size() == 0)
            {
                //then print error message
                cout << "Sorry. No History :(" << endl;
            }
            else //else, prints out the history of commands given
            {
                for(int i = 0; i < history.size(); i++)
                {
                    cout << i+1 << " " << history[i] << endl;
                }
            }
        }
        history.push_back(command1); //pushes the command elements at the end

        //parsing
        stringstream data(command1);
        string temp;
        char *args[10];
        int number = 0;
        //able to split the text entered by the user into the individual command line arguments that comprise it
		while(getline(data, temp, ' '))
		{
            args[number] = new char[temp.length() + 1];
            strcpy(args[number], temp.c_str());
            number++;
		}

        //redirection
        int cinLoc = dup(STDIN_FILENO); //input location declaration
        int coutLoc = dup(STDOUT_FILENO); //output location declaration
        //for loop to print the redirection
        for(int i = 0; i < number - 1; i++)
        {
            if(strcmp(args[i], ">") == 0)
            {
                int fd1 = open(args[i+1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
                dup2(fd1, STDOUT_FILENO); //create a copy of fd1 using standard output file descriptor to achieve the redirection
                close(fd1); //close the original file descriptor
                args[i] = NULL;
                args[i+1] = NULL;
            }
            else if(strcmp(args[i], "<") == 0)
            {
                int fd1 = open(args[i+1], O_RDONLY, 0644);
                dup2(fd1, STDIN_FILENO); //create a copy of fd1 using standard output file descriptor to achieve the redirection
                close(fd1); //close the original file descriptor
                args[i] = NULL;
                args[i+1] = NULL;
            }
        }
        
        forking(args); //running a fork with the execvp command
        //dup2 calls
        dup2(cinLoc, STDIN_FILENO);
        dup2(coutLoc, STDOUT_FILENO);
    }
    return 0;
}