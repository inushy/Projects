//******************************************************************
//
// CSCI 463 Assignment 2
//
// Author: Anushka Verma (Z1911937)
//
// Bitwise Operators & IEEE-754 Floating Point Number Decoding
//
//******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

/* ***************************************************************************
 * @param unit32_t x is used to print out values through my loops
 *
 * @note This function uses the C bitwise operators to extract, shift the 
 *       required fields of the IEEE number which would help us to display 
 *       the ouput as described in the test.out.txt file.
 *****************************************************************************/

void printBinFloat(uint32_t  x)
{
    int32_t signed_exponent = ((((x >> 23) & 0x000000ff)) - 127);

    cout << hex << "0x" << setw(8) << setfill('0') << x << " = ";   //Prints out both hex and binary value
    for(int i = 31; i >= 0; i--)  //Loop to print out binary value
    {
        cout << (((x >> i) & 0x00000001) ? '1':'0');
        if(i % 4 == 0 && i > 0)     //Formats the binary values by adding spaces in between
        {
            cout << " ";
        } 
    }
    cout << endl;   //Adds a new line
    cout << "sign: " << hex << (x & 0x80000000 ? '1':'0'); //Determines the sign of the 32-bits
    cout << endl;   //Adds a new line
    cout << " exp: " << hex << "0x" << setw(8) << setfill('0') << (((x & 0x7f800000) >> 23) - 127); //Exponent bits are 23-31, so shifting it 23, get's rid of the significand
    cout << dec << " (" << signed_exponent <<  ")"; //Prints the decimal value of the signed exponent
    cout << endl;   //Adds a new line
    cout << " sig: " << hex << "0x" << setw(8) << setfill('0') << (x & 0x007fffff); //Significand bits are 0-22
    
    if((x & 0x80000000) == 0) //If the sign bit equals 0
    {
        cout << endl;   //Adds a new line
        cout << "+";   //Then prints positive 
    }
    else
    {
        cout << endl;  //Adds a new line
        cout << "-";  //Otherwise, prints negative
    }

    int32_t exponent = ((((x >> 23) & 0x000000ff)) - 127);  //Created an exponent variable for further use

    if((((x & 0x7f800000) >> 23) - 127) == 0x00000080 && (x & 0x007fffff) == 0x00000000)    //If the exponent = the signed_bit && the significand equals 0
    {
        cout << "inf";   //Then it prints Infinity
        cout << endl;    //Adds a new line
    }
    else if(((((x & 0x7f800000) >> 23) - 127)) == 0xffffff81 && (x & 0x007fffff) == 0x00000000) //If exponent = 0xffffff81 && the significand equals 0x00000000
    {
        cout << "0";    //Then it prints 0
        cout << endl;   //Adds a new line
    }
    else if((int32_t((((x >> 23) & 0x000000ff)) - 127) > 0x00000000)) //If exponent is greater than 0x00000000
    {
        cout << "1";    //Then it prints 1
        uint32_t mask = 0x400000;   //Created an unsigned int mask of 0x400000

        int shift_bits = (((x & 0x7f800000) >> 23) - 127) - 23; //Shifts the decimal point all the way past the significand
        for(int i = 0; i < 23; i++)
        {
            cout << (x & mask ? '1' : '0');   //Prints the significand
            mask >>= 1;
        }
        for(int i = 0; i < shift_bits; i++) //Adds the zeros after the significand
        {
            cout << "0";
        }
        cout << ".0";   //Final zero
        cout << endl;   //Adds a new line
    }
    else if((int32_t((((x >> 23) & 0x000000ff)) - 127) < 0x00000000))   //If exponent is less than 0x00000000
    {
        cout << "0.";   //Then it prints 0.
        for(int i = -1; i > signed_exponent; i--)
        {
            cout << "0";
        }
        cout << "1";
        for(int i = 22; i >= 0; i--)
        {
            cout << ((x >> i) & 1 ? '1' : '0'); //Prints the significand
        }
        cout << endl;
    }
    else if(exponent == 0)  //If exponent is equal to 0
    {
        cout << "1";    //Then it prints 1
        cout << ".";    //And a "."
        uint32_t mask = 0x400000;   //Created an unsigned int mask of 0x400000

        for(int i = 0; i < 23; i++)
        {
            cout << (x & mask ? '1' : '0');   //Prints the significand
            mask >>= 1;
        }
        cout << endl;   //Adds a new line
    }
}

/* ****************************************************************************
 *
 * @return 0 used in the int main to end the main program
 *
 * @note This function basically displays the output.
 *****************************************************************************/

int main()
{
    uint32_t x; //initializing a variable called x

    //Reads your input from stdin (aka std::cin) or known as printBinFloat
    while(cin >> hex >> x)
    {
        printBinFloat(x); //Calls the printBinFloat that decodes and prints
    }
    return 0;
}