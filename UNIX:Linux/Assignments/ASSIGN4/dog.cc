/*
   Anushka Verma <Z1911937>
   Prof. Lehuta
   CSCI 330 Section - 1
   assign04 - Upgrading our basic implementation of the cat command using C++ 
*/
#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include "functions.h"


using namespace std;
int main(int argc, char *argv[])
{
	int option; //Initializing Option To Use In My GetOpt

	size_t buf_size = 1000;//================
	size_t num_byte = 0;//    		|
	int  caesar_shift_amount = 0;// 	|=== Used In The Switch For GetOpt 
	int  rotate_shift_amount = 0;//     	|
	bool hexad   = false;// 		|
	bool bin     = false;//==================

	while((option = getopt(argc, argv, "s:n:c:r:xb")) != -1) //Command Line Options
	{
		switch(option)
		{
			case 's':
				buf_size = atoi(optarg);
				break;
			case 'n':
				num_byte = atoi(optarg);
				break;
			case 'c':
				caesar_shift_amount = atoi(optarg);
				break;
			case 'r':
				rotate_shift_amount = atoi(optarg);
				break;
			case 'x':
				hexad = true;
				break;
			case 'b':
				bin = true;
				break;
			default:
				cerr << "Not Really Sure About What This -" << option << " Means. Sorry!" << endl;
				abort();
		}
	}

	if(hexad && bin)
	{
		cerr << "Cannot Represent Data As Both Binary And Hexadecimal!"<<endl;
		exit(1);
	}
	if(caesar_shift_amount && rotate_shift_amount)
	{
		cerr << "Sorry The Two Functions Are Not Compatiable Together!"<<endl;
		exit(2);
	}
	
	char buffer[buf_size]; //Buffer To Read The Data From
	char hexbuf[2 * buf_size]; //Buffer For The Hexadecimal Function
	char binbuf[8 * buf_size]; //Buffer For The Binary Function
	int fd; //Initializing File Descriptor  
	ssize_t nr; //Number Of Bytes Successfully Read And Written

	if(argc > 1)
	{
		for (int i = optind; i < argc; i++)  //The Loop For Total Argument
		{
			if(strcmp("-", argv[optind]) == 0) //Sorry The File Name Cannot Be "-"
			{
				
				fd = 0; //Sets fd To Standard Input

			}
			else
			{
				fd = open(argv[optind], O_RDONLY); //System Call To Open File

				if(fd == -1)
				{
					char warning[500] = "Error Opening File: ";
					strcat(warning, argv[optind]);
					perror(warning);
					return 2;

				}
			}
			
			do{
				nr = read(fd, buffer, buf_size);
				if(caesar_shift_amount)
				{
					caesar(buffer, nr, caesar_shift_amount);
				}
				else if(rotate_shift_amount)
				{
					rotate(buffer, nr, rotate_shift_amount);
				}
				if(hexad)
				{
					tHex(buffer, nr, hexbuf);
					write(1, hexbuf, 2*nr);
				}
				else if(bin)
				{
					tBinary(buffer, nr, binbuf);
					write(1, binbuf, 8*nr);
				}
				else
					write(1, buffer, nr);

			} while (nr > 0);

			close(fd); //Clean And Close The File
				
		}
				
	}
	else
	{
		cerr << "I don't understand what to do!" <<endl;
		return 1;
	}



	return 0;
}

