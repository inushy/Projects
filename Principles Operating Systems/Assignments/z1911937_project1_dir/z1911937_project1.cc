/********************************************************************
CSCI 480 - Assignment 1 - Semester (Spring) 2022

Progammer: Anushka Verma
Section:   001
TA:        Mosab Rezaei
Date Due:  02/05/2022

Purpose:   This is a program that helps to practice system calls such
           as fork(). This would start the child procces using fork().
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
    //Process identification data types to declare a variables for the fork processes
    pid_t parPID = fork();
    pid_t parInterPID = fork();

    //If parPID (my fork 1) is greater than 0
    if(parPID > 0)
    {
        //And if parInterPID (my fork 2) is greater than 0
        if(parInterPID > 0)
        {
            //Prints the initial parent process
            cout << "PARENT: My PID is " << getpid() << ", my parent's PID is " << getppid() << ", my children are ";
            cout << parPID << ", " << parInterPID << "." << endl;
            sleep(1);
            
            ostringstream os;   //Output string stream variable

            //Ostringstream variable that contains the command which would display all the objects and prints
            //The issuing command and their PID's
            os << "ps -f --ppid " << getpid() << "," << getppid() << "," << parPID << "," << parInterPID;
            cout << "PARENT: Issuing command: /bin/ps -f --ppid " << getpid() << ", " << getppid() << ", ";
            cout << parPID << ", " << parInterPID << endl;
            system(os.str().c_str());  //System call for the output string stream 
            //Waiting for all child processes to be completed then prints the completion message and exits
            wait(NULL);
            wait(NULL);
            cout << "PARENT: Children processes are finished." << endl;
        }
        //Otherwise, it prints the intermediate parent PID
        else
        {
            cout << "INTERMEDIATE PARENT: My PID is " << getpid() << ", my parent's PID is " << getppid();
            cout << ", my child is " << parPID << "." << endl;
            sleep(3); //After the information get's printed, process sleeps for 3 seconds
            //Then prints the following message and exits.
            cout << "INTERMEDIATE PARENT: " << getpid() << " is awake." << endl;
        }
    }

    //Else if parPID (my fork 1) equals 0
    else if(parPID == 0)
    {
        //If parInterPID (my fork 2) is greater than 0
        if(parInterPID > 0)
        {
            //Then print out the child PID
            cout << "CHILD: My PID is " << getpid() << ", my parent's PID is " << getppid() << "." << endl;
            sleep(3); //After the information get's printed, process sleeps for 3 seconds
            //Then prints the following message and exits.
            cout << "CHILD: " << getpid() << " is awake." << endl;
        }
        //Otherwise, Print out the Grand Child and their PID
        else
        {
            cout << "GRAND CHILD: My PID is " << getpid() << ", my parent's PID is " << getppid() << "." << endl;
            sleep(3); //After the information get's printed, process sleeps for 3 seconds
            //Then prints the following message and exits.
            cout << "GRAND CHILD: " << getpid() << " is awake." << endl;
        }
    }
    return 0;
}