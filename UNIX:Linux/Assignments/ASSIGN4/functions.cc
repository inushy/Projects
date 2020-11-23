/*
   Anushka Verma <Z1911937>
   Prof. Lehuta
   CSCI 330 Section - 1
   assign04 - Upgrading our basic implementation of the cat command using C++ 
*/

#include "functions.h"

using namespace std;
void caesar(char* buffer, size_t limit, int shAmount)
{
    for(size_t i = 0; i < limit; i++)
    {
        if(buffer[i] >= 'A' && buffer[i] <= 'Z')//Check For Capital Letters
        {
	    buffer[i] = (buffer[i] - 'A' + shAmount) % 26 + 'A';
        }
	else if(buffer[i] >= 'a' && buffer[i] <= 'z')//Check For Non-Capital Letters
        {
	    buffer[i] = (buffer[i] - 'a' + shAmount) % 26 + 'a';
        }
    }
}

void rotate(char* buffer, size_t limit, int shAmount)
{
    for(size_t i = 0; i < limit; i++)
    {
	buffer[i] = (buffer[i] + shAmount) % 256;
    }
}

void tBinary(char* buffer, size_t limit, char* binbuf)
{ 
    for(size_t i = 0; i < limit; i++)
    {
	binbuf[8*i+0] =  ((buffer[i] & 128) >> 7) + 48;
	binbuf[8*i+1] =  ((buffer[i] & 64) >> 6) + 48;
	binbuf[8*i+2] =  ((buffer[i] & 32) >> 5) + 48;
	binbuf[8*i+3] =  ((buffer[i] & 16) >> 4) + 48;
	binbuf[8*i+4] =  ((buffer[i] & 8) >> 3) + 48;
	binbuf[8*i+5] =  ((buffer[i] & 4) >> 2) + 48;
	binbuf[8*i+6] =  ((buffer[i] & 2) >> 1) + 48;
	binbuf[8*i+7] =  ((buffer[i] & 1) >> 0) + 48;	
    }
}

void tHex(char* buffer, size_t limit, char* hexbuf)
{
    for(size_t i = 0; i < limit; i++)
    {
	char hex[] = "0123456789ABCDEF";
	hexbuf[2*i+0] = hex[((buffer[i] & 0xF0) >> 4)]; //char 0-F
	hexbuf[2*i+1] = hex[((buffer[i] & 0x0F) >> 0)];

    }
}


