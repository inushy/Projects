/*
   Anushka Verma <Z1911937>
   Prof. Lehuta
   CSCI 330 Section - 1
   assign03 - Creating a basic implementation of the cat command using C++ 
*/

#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


using namespace std;

int main(int argc, char *argv[])
{
	char buffer[1000]; //Buffer To Read The Data From
	int fd, i;  //Initializing File Descriptor

	if(argc > 1)
	{
		for (i = 1; i < argc; i++)  //The Loop For Total Argument
		{

			fd = open(argv[1], O_RDONLY); //System Call To Open File
			if(fd == -1)
			{
				perror("open");
				return 2;
			}
			cout << fd <<endl;

			ssize_t nr;  //Number Of Bytes Successfully Read
			nr = read(fd, buffer, 999); //Bytes Read From A File
			if(nr == -1) //Prints Out What The Error Is, If Any
			{
				perror("read");
				return 3;
			}

			buffer[nr] = 0;
			cout << "read " << nr << " bytes: \"";

			cout << i << ") '" << buffer[i] << "'" << " -> " << (int) buffer[i] <<endl;

			cout.flush(); //Flushes The Buffer
	       

	       		ssize_t nw; //Numbers Written
	       		nw = write(1, buffer, nr); //Writing To A File

	       		cout << "\"" << endl;
			

		}

	}
	else
	{
		cerr << "I don't understand what to do!" <<endl;
		return 1;
	}

	close(fd); //Clean And Close The File

	return 0;
}
