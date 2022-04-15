/********************************************************************
CSCI 480 - Assignment 4 - Semester (Spring) 2022

Progammer: Anushka Verma
Section:   001
TA:        Mosab Rezaei
Date Due:  03/30/2022
Extension: 04/05/2022
Purpose:   This is a program that helps to simulates CPU scheduling 
           in an operating system.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>
#include "process.h"

using namespace std;

#define MAX_TIME 500
#define IN_USE 5
#define HOW_OFTEN 25
#define QUEUE_SIZE 20

//Deques
deque<Process*> entryQueue;
deque<Process*> readyQueue;
deque<Process*> inputQueue;
deque<Process*> outputQueue;

Process* active;
Process* iactive;
Process* oactive;

//Global variables
int timer = 0;
int idleTimer = 0;
int finishedProcesses = 0;
int totalWaitTime = 0;

//Makes sure that the active, iactive, oactive's are not a nullptr
//to help increment the size of the ready queue
int inplay()
{
    int value = readyQueue.size();

    if(active != nullptr)
    {
        value++;
    }
    if(iactive != nullptr)
    {
        value++;
    }
    if(oactive != nullptr)
    {
        value++;
    }

    value += inputQueue.size();
    value += outputQueue.size();

    return value;
}

//Prints whether the deques are empty or have the processID within them
void dequeInfo(deque<Process*> &procs)
{
    if(procs.empty())
    {
        cout << "(Empty)" << endl;
    }
    else
    {
        for(size_t i = 0; i < procs.size(); i++)
        {
            cout << procs.at(i)->processID << " ";
        }
        cout << endl;
    }
}

void systemDetails() //Prints the state of the system
{
    //If the active status of the processName is not NULL
    if (active != NULL) 
    {
        //Then print the processID of the active state
        cout << "Active is " << active->processID;
        cout << endl;
    }
    else
    {
        cout << "Active is 0" << endl;
    }
    if(iactive != NULL)
    {
        //Then print the processID of the active state
        cout << "IActive is " << iactive->processID;
        cout << endl;
    }
    else
    {
        cout << "IActive is 0" << endl;
    }
    if(oactive != NULL)
    {
        //Then print the processID of the active state
        cout << "OActive is " << oactive->processID;
        cout << endl;
    }
    else
    {
        cout << "OActive is 0" << endl;
    }

    //Print the contents of each queue
    cout << "Contents of the Entry Queue ";
    cout << endl;
    dequeInfo(entryQueue);
    cout << "Contents of the Ready Queue: ";
    cout << endl;
    dequeInfo(readyQueue);
    cout << "Contents of the Input Queue: ";
    cout << endl;
    dequeInfo(inputQueue);
    cout << "Contents of the Output Queue: ";
    cout << endl;
    dequeInfo(outputQueue);
    cout << endl << endl;
    
}

//Checks to see if the queues and the active, iactive, oactive statuses are NULL/empty
//Returns if they are empty/NULL and returns false if they aren't
bool isEmpty()
{
    bool status1 = active == NULL;
    bool status2 = iactive == NULL;
    bool status3 = oactive == NULL;

    if(entryQueue.empty() && readyQueue.empty() && inputQueue.empty() && outputQueue.empty() 
        && status1 == true && status2 == true && status3 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void endProcessDetails(Process* p) //Prints the end process details
{
    cout << "Process " << p->processID << " has ended.";
    cout << endl;

    cout << "Name: " << p->processName;
    cout << endl;

    cout << "Started at time " << p->startTime;
    cout << " and ended at time " << timer;
    cout << endl;

    cout << "Total CPU time = " << p->cpuTotal;
    cout << " in " << p->cpuCount;
    cout << " CPU bursts";
    cout << endl;

    cout << "Total Input time =  " << p->iTotal;
    cout << " in " << p->iCount;
    cout << " Input bursts";
    cout << endl;

    cout << "Total Output time =  " << p->oTotal;
    cout << " in " << p->oCount;
    cout << " Output bursts";
    cout << endl;

    cout << "Time spent in waiting:  " << p->waitTimer;
    cout << endl << endl;
}

int main(int argc, char* argv[])
{
    //Variables
    string file; //Declaring file as a string

    //If there are 2 arguements
    if(argc == 2)
    {
        file = argv[1]; //Then access the file
    }
    else //Otherwise, print error message
    {
        cerr << "Sorry, But You Need 2 Arguements! " << endl;
        exit(0);
    }
    
    //More variables
    ifstream filename; //Reads the file
    filename.open(file);
    string initialName; //Declaring initialName as a string
    int arrival; //Declaring arrival as integer variable
    
    //Current process pointer set to NULL
    Process* procs = nullptr; 

    //While in the file..
    while(filename)
    {
        //Storing the process name and the arrival time
        filename >> initialName >> arrival; 
        procs =  new Process(initialName, arrival);

        //If the process name is "STOPHERE"
        if(procs->processName == "STOPHERE")
        {
            //Then quit
            break; 
        }
        else
        {
            //More variables
            //String variables to store data
            string letter;
            string num; 

            for (int i = 0; i != 10; i++)
            {
                filename >> letter >> num; 

                //Conversion of character to an integer
                char type = letter[0];
                int value = stoi(num);

                //Put the value pairs into the vector history
                procs->history.push_back(pair<char,int>(type,value));
            }
            entryQueue.push_back(procs);

        }
    }

    //Title of the simulation scheduling
    cout << "Simulation of CPU Scheduling";
    cout << endl << endl;
    while(timer < MAX_TIME && isEmpty() == false)
    {
        //Setting my processes variable to the inplay function
        int processes = inplay();

        //If active is NULL and the readyQueue is empty and the entryQueue is not empty and the processes is less than 5
        if(active == NULL && readyQueue.empty() && !entryQueue.empty() && processes < IN_USE)
        {
            for(size_t i = 0; i < entryQueue.size();)
            {
                //Creating a temporary pointer and setting it to the entryQueue
                Process* temp = entryQueue.at(i);

                //If timer is greater and equal to the arrivalTime and processes is still less than 5
                //then pushes it to the readyQueue.
                if(timer >= temp->arrivalTime && processes < IN_USE)
                {
                    temp->startTime = timer;
                    readyQueue.push_back(temp);
                    cout << "Process " << temp->processID;
                    cout << " moved from the Entry Queue into the Ready Queue at time " << timer;
                    cout << endl << endl;
                    entryQueue.erase(entryQueue.begin()+i);
                    ++processes;
                }
                else
                {
                    ++i;
                }
            }
        }
        if (timer % HOW_OFTEN == 0)
        {
            cout << "Status at time " << timer << endl; //Prints the time of the status
            systemDetails();  //Prints the rest of the system details at 25
        }

        //If active equals NULL
        if(active == NULL)
        {
            //If the readyQueue is not empty
            if(!readyQueue.empty())
            {
                //Fills active by storing the the first elements of the readyQueue
                active = readyQueue.front();
                readyQueue.pop_front(); //Clears the readyQueue
            }
            else
            {
                //Otherwise print the time when active is 0.
                cout << "At time " << timer;
                cout << " Active is 0, so we have idle time for a while";
                cout << endl << endl;
                ++idleTimer; //Increments the idleTimer
            }
        }
        //If active is not NULL
        if(active != NULL)
        {
            //If the cpuTimer is less than the history at the second element
            if(active->cpuTimer < active->history.at(active->sub).second)
            {
                //Increments the cpuTimer and the cpuTotal
                active->cpuTimer++;
                active->cpuTotal++;
            }

            //If the cpuTimer is equal to the history at the second element
            if(active->cpuTimer == active->history.at(active->sub).second)
            {
                active->cpuTimer = 0; //Set the cpuTimer to 0
                active->cpuCount++; //Increment the cpuCount
                active->sub++;  //Increment the sub history

                //Setting the next character to the first element of the history
                char next = active->history.at(active->sub).first;

                //If the the next character equals the letter I
                if(next == 'I')
                {
                    //Then adds the new active element to the inputQueue
                    inputQueue.push_back(active);
                }
                
                //Else if the next character equals the letter O
                else if(next == 'O')
                {
                    //Then adds the new active element to the outputQueue
                    outputQueue.push_back(active);
                }

                //Otherwise,
                else
                {
                    //Completes the process
                    active->waitTimer = timer - active->startTime - active->cpuTotal - active->iTotal - active->oTotal;
                    endProcessDetails(active);
                    ++finishedProcesses;
                    totalWaitTime += active->waitTimer;
                }
                active = NULL;
            }
        }

        //If iactive is NULL
        if(iactive == NULL)
        {
            //And if the inputQueue is not empty
            if(!inputQueue.empty())
            {
                //Fills iactive by storing the the first elements of the inputQueue
                iactive = inputQueue.front();
                inputQueue.pop_front(); //Clears the inputQueue
            }
        }

        //If iactive is not NULL
        if(iactive != NULL)
        {
            //If the iTimer is less than the history at the second element
            if(iactive->iTimer < iactive->history.at(iactive->sub).second)
            {
                //Increments the iTimer and the iTotal
                iactive->iTimer++;
                iactive->iTotal++;
            }

            //If the iTimer is equal to the history at the second element
            if(iactive->iTimer == iactive->history.at(iactive->sub).second)
            {
                iactive->iTimer = 0; //Set the iTimer to 0
                iactive->iCount++; //Increment the iCount
                iactive->sub++;  //Increment the sub history
                readyQueue.push_back(iactive); //Adds the new iactive element to the readyQueue
                iactive = NULL;
            }
        }

        //If oactive is NULL
        if(oactive == NULL)
        {
            //And if the outputQueue is not empty
            if(!outputQueue.empty())
            {
                //Fills oactive by storing the the first elements of the outputQueue
                oactive = outputQueue.front();
                outputQueue.pop_front(); //Clears the outputQueue
            }
        }

        //If oactive is not NULL
        if(oactive != NULL)
        {
            //If the oTimer is less than the history at the second element
            if(oactive->oTimer < oactive->history.at(oactive->sub).second)
            {
                //Increments the oTimer and the oTotal
                oactive->oTimer++;
                oactive->oTotal++;
            }

            //If the oTimer is equal to the history at the second element
            if(oactive->oTimer == oactive->history.at(oactive->sub).second)
            {
                oactive->oTimer = 0; //Set the oTimer to 0
                oactive->oCount++; //Increment the oCount
                oactive->sub++;  //Increment the sub history
                readyQueue.push_back(oactive); //Adds the new oactive element to the readyQueue
                oactive = NULL;
            }
        }
        ++timer; //Increments the timer
    }

    //Final output of the scheduler
    cout << "The run has ended.";
    cout << endl;
    cout << "The final value of the timer was: " << timer;
    cout << endl;
    cout << "The amount of time spent idle was: " << idleTimer;
    cout << endl;
    cout << "Number of terminated processes = " << finishedProcesses;
    cout << endl;
    cout << "Average waiting time for all terminated processes = " << totalWaitTime/finishedProcesses;
    cout << endl;
    systemDetails();
    return 0;
}