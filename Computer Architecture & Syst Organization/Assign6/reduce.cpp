//******************************************************************
//
// CSCI 463 Assignment 6
//
// Author: Anushka Verma (Z1911937)
//
// Sum the contents of a 2D matrix in a multithreaded application 
// that uses static or dynamic load balancing based on a 
// command-line argument.
//
//******************************************************************

#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <cstdlib>

using namespace std;

constexpr int rows = 1000;      ///< the number of rows in the work matrix
constexpr int cols = 100;       ///< the number of cols in the work matrix

mutex stdout_lock;              ///< for serializing access to stdout

mutex counter_lock;             ///< for dynamic balancing only
volatile int counter = rows;    ///< for dynamic balancing only

vector<int> tcount;             ///< count of rows summed for each thread
vector <uint64_t > sum;         ///< the calculated sum from each thread

int work[rows][cols];           ///< the matrix to be summed

/**
 * This function helps to implement the logic needed to sum the rows 
 *  of the matrix using static load balancing to determine 
 *  which rows will be processed by each thread
 * 
 * @param tid Parameter used as the thread ID
 * @param num_threads Parameter used to describe the number of threads that
 *  determine the next row process
 ********************************************************************************/

void sum_static(int tid, int num_threads)
{
    stdout_lock.lock(); 
    cout <<  "Thread " << tid << " starting";   //Display's which thread ID is starting
    cout << endl;
    stdout_lock.unlock();

    bool stop = false;  //Used in the while loop to tell us when to stop going through the rows
    int c = 0;  //Initialized count to equal to 0
    while(!stop)
    {
        int r = tid + (num_threads * c);    //Initializing the next row to add up
        ++c;    //Increments and then assigns the count value

        if(r >= rows)   //If the next row is greater than or equal to the number of rows
        {
            stop = true;    //Then stop adding it
        }

        else if(!stop)  //Otherwise, if it doesn't stop adding up 
        {
            uint64_t t = 0; //Initializes the total to equal 0

            //For each column in the row,
            for(int i = 0; i < cols; ++i)
            {
                //Sum the matrix to get the total value
                t += work[r][i];
            }

            //The sum of each row that gets counted to the total value
            sum[tid] += t;
            ++tcount[tid]; //Totals up the number of work that the thread ID had completed
        }
    }

    stdout_lock.lock();
    cout <<  "Thread " << tid << " ending tcount=" << tcount[tid] << " sum=" << sum[tid];
    cout << endl;
    stdout_lock.unlock();
}

/**
 * This function helps to implement the logic needed to sum the rows of 
 *  the matrix using dynamic load balancing to determine 
 *  which rows will be processed by each thread.
 * 
 * @param tid Parameter used as the thread ID
 ********************************************************************************/

void sum_dynamic(int tid)
{
    stdout_lock.lock();
    cout <<  "Thread " << tid << " starting";   //Display's which thread ID is starting
    cout << endl;
    stdout_lock.unlock();

    bool stop = false;  //Used in the while loop to tell us when to stop going through the rows
    while(!stop)
    {
        int count_copy; //Initializes the counter copy
        counter_lock.lock();
        {
            if(counter > 0) //If the counter is greater than 0
            {
                --counter;  //Then decrement the counter
            }
            else    //Otherwise,
            {
                stop = true;    //Stop adding it
            }

            count_copy = counter;   //Counter copy is then equalled to the counter
        }
        counter_lock.unlock();

        if(!stop)   //If it doesn't stop adding up
        {
            //For each column in the row,
            for(int i= 0; i < cols; ++i)
            {
                //Sum each row that gets counted to the total value of the matrix to get the total value
                sum[tid] += work[count_copy][i];
            }
            ++tcount[tid];  //Totals up the number of work that the thread ID had completed
        }
    }

    stdout_lock.lock();
    cout <<  "Thread " << tid << " ending" << " tcount=" << tcount[tid] << " sum=" << sum[tid];
    cout << endl;
    stdout_lock.unlock();
}

/**
 * @note This function prints the error message and pattern to standard error
 * and terminates the program in the traditional manner
 ********************************************************************************/

static void usage()
{
    cerr << "Usage: reduce [-d] [-t num]" << endl;
    cerr << "     -d use dynamic load-balancing" << endl;
    cerr << "     -t specifies the number of threads to use" << endl;
    exit(1);
}

/**
 * This function helps to accept the command-line parameters
 * 
 * @param argc Argument Count
 * @param argv Argument Vector
 * 
 * @return 0
 ********************************************************************************/

int main(int argc, char **argv)
{
    int opt;  //Initializes the option variable
    bool dynamic_load = false;  //Boolean of the dynamic case when the option is used
    int total_work = 0; //Initializes the total work to 0
    uint64_t gross_sum = 0; //Initializes the gross sum to 0
    int num = 2; //Initializes the number of threads which is defaulted to 2
    int i;  //Initializes i that gets used in for loops
    int j;  //Initializes j that gets used in for loops
    int number_of_threads = thread::hardware_concurrency(); //Initializes the number of threads that is used by the system
    srand(0x1234);  //Seeds your random number generator
    vector<thread*> threads;    //Vector that holds all the threads that are being used

    while ((opt = getopt(argc, argv, "dt:")) != -1)
    {
        switch (opt)
        {
            case 'd':
            {
                //Use dynamic load-balancing. (By default, use static load balancing.)
                dynamic_load = true;
            }
            break;

            case 't':
            {
                // Specifies the number of threads to use. (By default, start two threads.)
                num = atoi(optarg);
                if(num > number_of_threads) //If the number is greater than the number of threads,
                {
                    num = number_of_threads; //Then equal the number to the number of threads
                }
                else if (num < 0)    //Else if, the number is less than 0
                {
                    usage();  //Then, display usage errors
                }
            }
            break;
            default:
            {
                usage();   //Display's usage errors
            }
        }
    }

    tcount.resize(num, 0);  //Resizes the total count 
    sum.resize(num, 0); //Resizes the sum
    
    //For each rows and columns
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            work[i][j] = rand();    //Randomly initialize the work matrix
        }
    }
    cout << number_of_threads << " concurrent threads supported.";  //Prints the number of threads the concurrent threads support
    cout << endl;   //Prints a new line

    //If the user inputs the command -d, 
    if(dynamic_load)
    {
        //Then by using the dynamic load balancing, 
        for(i = 0; i < num; ++i)
        {
            //Calls the sum_dynamic function
            threads.push_back(new thread(sum_dynamic, i));
        }
    }
    else  //Otherwise,
    {
        for(i = 0; i < num; ++i)
        {
            //Calls the sum_dynamic function
            threads.push_back(new thread(sum_static, i, num));
        }
    }

    for(i = 0; i < num; ++i)
    {
        threads.at(i) -> join();  //Joins the threads
        delete threads.at(i);   //Then deletes the threads
        total_work += tcount.at(i); //Then calculates the total work 
        gross_sum += sum[i];   //And the gross sum of the threads
    }
    
    cout << "main() exiting, total_work=" << total_work << " gross_sum=" << gross_sum;
    cout << endl;
    return 0;
}