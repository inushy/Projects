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
#include <string>
#include <vector>

using namespace std; 

#ifndef PROCESS_H
#define PROCESS_H
#define ARRAY_SIZE 10  //Size of the array to define in a process

class Process
{
    public:
        Process();
        Process(string pName, int pArrival);
        string processName; //Name of the process
        static int pID;
        int processID; //ID number for the process
        int arrivalTime = 0;  //Initializing arrival time to 0
        vector<pair<char,int> >history; //Making a vector pair for the history of the processes
        int sub = 0; //Subscript used in the vector History
        int cpuTimer = 0; //Counts clock ticks for the process until it reaches the end of the CPU burst for FCFS
        int startTime = 0;
        int iTimer = 0; //Counts clock ticks for the process until it reaches the end of the I/O burst
        int oTimer = 0; //Counts clock ticks for the process until it reaches the end of the I/O burst
        int cpuTotal = 0; //Accumulates the number of clock ticks the process spends as Active
        int iTotal = 0; //Accumulates the number of clock ticks the process spends as IOActive
        int oTotal = 0; //Accumulates the number of clock ticks the process spends as IOActive
        int cpuCount = 0; //Counts the number of completed CPU bursts for this process
        int iCount = 0; //Counts the number of completed I/O bursts for this process
        int oCount = 0; //Counts the number of completed I/O bursts for this process
        int waitTimer = 0;
};

//Default constructors
Process::Process(){}
Process::Process(string pName, int pArrival)
{
    processName = pName;
    arrivalTime = pArrival;
    processID = ++pID;
}

int Process::pID = 100;
#endif