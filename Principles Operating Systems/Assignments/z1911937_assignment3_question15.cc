/********************************************************************
CSCI 480 - Assignment 3(Question 15) - Semester (Spring) 2022

Progammer: Anushka Verma
Section:   001
TA:        Mosab Rezaei
Date Due:  03/04/2022
Purpose:   This is a program that helps the fork() system call to 
           generate the sequence in the child process.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int colConject(int numericalValue)
{
    //if my numericalValue is even
    if(numericalValue % 2 == 0)
    {
        if(numericalValue/2 != 1)
        {
            cout << numericalValue/2 << ", "; //then it performs the following algorithm to print the 
                                              //value with a separator in between
        }
        return colConject(numericalValue/2);
    }
    
    //else if my numericalValue is equal to 1 (base case)
    else if(numericalValue == 1)
    {
        cout << numericalValue << endl; //prints the 1 at the end of the output
        return 0;
    }

    //else it is the odd value 
    else
    {
        //setting my integer odd value counter to the algorithm which will allow positive integers to print
        int oddValuec = 3*numericalValue + 1;
        if(oddValuec != 1)
        {
            cout << oddValuec << ", ";
        }
        return colConject(oddValuec);
    }
}

bool forking(int numValue)
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
        cout << numValue << ", "; //prints the int numValue and the following numbers with a comma (separator) between them
        colConject(numValue); //passing the parameter into my collatz conjunture functions
        exit(0);
    }
    else
    {
        wait(NULL);
    }
    return false;
}

int main()
{
    int num;
    cout << "Please Enter A (Pos) Number: "; //prompting the user to input a positive value
    cin >> num; //getting user input
    while(num < 1) //if the number is less than 1
    {
        //then prints the error message along with the prompt again for the user to re-input their positive value
        cout << "Sorry Please Try Again!" << endl << endl;
        cout << "Enter A (Pos) Number: ";
        cin >> num;
    }
    //calls my fork function
    forking(num);
    return 0;
}