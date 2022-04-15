/********************************************************************
CSCI 480 - Assignment 5 - Semester (Spring) 2022

Progammer: Anushka Verma
Section:   001
TA:        Mosab Rezaei
Date Due:  04/16/2022
Purpose:   This is a program that helps to solve the Reader-Writer 
           problem using the PThreads library.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <cstdint>

using namespace std;

//Global variable shared by all threads
string phrase = "All work and no play makes Jack a dull boy.";
int readcount = 0; //Keeps track of readers

//Semaphores
sem_t rw_sem; //Used by both readers and writers
sem_t cs_sem; //Used for protecting critical sections of readers

void *writer(void *param)
{
    //some local variables
    int num = (long)param;

    //Loop until the string is empty:
    //Error checking
    if(phrase.empty() == true)
    {
        perror("Error: Check The Writer Please! \n");
        exit(-1);
    }
    else
    {
        if(phrase.empty() != true)
        {
            while(!phrase.empty())
            {
                //Wait operation before it writes to the shared string.
                sem_wait(&rw_sem);
                fflush(stdout);

                string wPrint1 = "writer";
                string wPrint2 = "is writing ...";

                //If the string is not empty then...
                if(!phrase.empty())
                {
                    //Chop the last character of the string until empty
                    phrase.pop_back();

                    //print out a message saying that it is writing
                    printf("%s %d %s\n", wPrint1.c_str(), num, wPrint2.c_str());
                }

                //Signals the writer
                sem_post(&rw_sem);

                //sleep for 1 second
                sleep(1);
            }
        }        
    }

    //When the string is empty then exit with the Id
    string wExit1 = "writer";
    string wExit2 = "is exiting ...";
    printf("%s %d %s \n", wExit1.c_str(), num, wExit2.c_str());
    pthread_exit(NULL);
}

void *reader(void *param)
{
    //some local variables
    int num = (long)param;
    
    //Loop until the string is empty:
    //Error checking
    if(phrase.empty() == true)
    {
        perror("Error: Check Reader Please! \n");
        exit(-1);
    }
    else
    {
        if(phrase.empty() != true)
        {
            //print out a message saying that it is reading
            while(!phrase.empty())
            {
                //Wait operation before entering the critical section.
                sem_wait(&cs_sem);
                readcount++; //Increments the readcount
                string rPrintIncre = "read_count increments to:";

                printf("%s %d \n", rPrintIncre.c_str(), readcount);

                //When the readcount is 1
                if(readcount == 1)
                {
                    //Then wait before it writes to the shared string
                    sem_wait(&rw_sem);
                }
                
                sem_post(&cs_sem);
                fflush(stdout); //Flushes the output buffer

                string rPrint1 = "reader";
                string rPrint2 = "is reading ... content :";

                if(phrase != "")
                {
                    //print out a message saying that it is reading
                    printf("%s %d %s %s \n", rPrint1.c_str(), num, rPrint2.c_str(), phrase.c_str());
                }

                sem_wait(&cs_sem);
                readcount--; //Decrements the readcount
                fflush(stdout);
                string rPrintDecre = "read_count decrements to:";

                printf("%s %d \n", rPrintDecre.c_str(), readcount);

                //When the readcount is 0
                if(readcount == 0)
                {
                    //Then the reader calls sem_post() on one semaphore
                    sem_post(&rw_sem);
                }

                //Signals the reader
                sem_post(&cs_sem);

                //sleep for 1 second
                sleep(1);
            }
        }       
    }

    //When the string is empty then exit with the Id
    string rExit1 = "reader";
    string rExit2 = "is exiting ..."; 
    printf("%s %d %s \n", rExit1.c_str(), num, rExit2.c_str());
    pthread_exit(NULL);
}

//Prints the error messages and terminates the program in the traditional manner
void usage()
{
    perror("Usage: z1911937_project5 <Number of reader threads>");
    perror(" <Number of writer threads> \n");
}

void emptySemaError()
{
    perror("Error: Sorry, problem initializing an empty semaphore! \n");
    exit(-1);
}

int main(int argc, char* argv[])
{
    //Variable declarations
    int readerQuantity = atoi(argv[1]);
    int writerQuantity = atoi(argv[2]);
    string title = "*** Reader-Writer Problem Simulation ***";
    string numReadThreadsPrint = "Number of reader threads:";
    string numWriteThreadsPrint = "Number of writer threads:";
    string completeThreadMessage = "All threads are done.";
    string cleanUpMessage = "Resources cleaned up.";

    //Get command line arguments. 
    if(argc < 2)
    {
        usage();
        return -1;
    }
    else
    {
        //Prints the info
        printf("%s \n", title.c_str());
        printf("%s %d \n", numReadThreadsPrint.c_str(), readerQuantity);
        printf("%s %d \n", numWriteThreadsPrint.c_str(), writerQuantity);
    }

    //Initialization of semaphores.
    int sema1 = sem_init(&rw_sem, 0, 1); 
    int sema2 = sem_init(&cs_sem, 0, 1);

    //Error checking with the semaphores
    if(sema1 < 0)
    {
        emptySemaError();
    }

    if(sema2 < 0)
    {
        emptySemaError();
    }

    //Create reader and writer threads.
    pthread_t rThreads[readerQuantity];
    pthread_t wThreads[writerQuantity];

    for(int i = 0; i < readerQuantity; i++)
    {
        int readThreadError = pthread_create(&rThreads[i], NULL, reader, (void*)(intptr_t) i);
        if(readThreadError != 0)
        {
            perror("Sorry, but couldn't create reader thread! \n");
            exit(-1);
        }
    }

    for(int i = 0; i < writerQuantity; i++)
    {
        int writeThreadError = pthread_create(&wThreads[i], NULL, writer, (void*)(intptr_t) i);
        if(writeThreadError != 0)
        {
            perror("Sorry, but couldn't create writer thread! \n");
            exit(-1);
        }
    }

    //Wait for reader threads to finish. 
    for(int i = 0; i < readerQuantity; i++)
    {
        int joiningReaderThread = pthread_join(rThreads[i], NULL);
        if(joiningReaderThread != 0)
        {
            perror("Sorry, but couldn't join reader threads! \n");
            exit(-1);
        }
    }

    //Wait for writer threads to finish.
    for(int i = 0; i < writerQuantity; i++)
    {
        int joiningWriterThread = pthread_join(wThreads[i], NULL);
        if(joiningWriterThread != 0)
        {
            perror("Sorry, but couldn't join writer threads! \n");
            exit(-1);
        }
    }

    //Prints the completed threads message
    printf("%s \n",completeThreadMessage.c_str());
    fflush(stdout);

    //Destroys the semaphores
    sem_destroy(&rw_sem);
    sem_destroy(&cs_sem);

    //Cleanup and exit.
    printf("%s \n",cleanUpMessage.c_str());
    fflush(stdout);
    pthread_exit(NULL);

    return 0;
}