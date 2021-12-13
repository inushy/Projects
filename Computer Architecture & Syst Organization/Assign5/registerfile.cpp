//******************************************************************
//
// CSCI 463 Assignment 5
//
// Author: Anushka Verma (Z1911937)
//
// Extended the functionality of our RISC-V disassembler to also 
// simulate the execution of a binary file.
//
//******************************************************************

#include <iostream>
#include <iomanip>
#include "registerfile.h"
#include "hex.h"

using namespace std;

/**
 * This function helps to Initialize register x0 to zero, 
 *  and all other registers to 0xf0f0f0f0.
 ********************************************************************************/

void registerfile::reset()
{
    //Initializing masks..
    int32_t regs_mask = 0xf0f0f0f0; //..for all other registers
    int32_t reg_mask = 0;  //..for register x0

    //Helps to set all the other 32 registers to regs_mask with the help of the vector
    registers.resize(32,regs_mask);
    
    //Otherwise it helps to set the register x0 to reg_mask
    registers.at(0) = reg_mask; 
}

/**
 * This function helps to assign register r the given val. If r is zero then do nothing
 * 
 * @param r Assigned register
 * @param val Given val that gets stored in the assigned register
 * 
 ********************************************************************************/

void registerfile::set(uint32_t r, int32_t val)
{
    //If the assigned register is not equal to 0
    if(r > 0 && r < 32)
    {
        //Then it stores the value in the assigned register
        registers.at(r) = val;
    }
}

/**
 * This function helps to return the value of register r. If r is zero then return zero
 * 
 * @param r Assigned register
 * 
 * @return The value of register r 
 ********************************************************************************/

int32_t registerfile::get(uint32_t r) const
{
    //If the assigned register is not equal to 0
    if(r > 0 && r < 32)
    {
        //The it returns the value of the assigned register, r 
        return registers.at(r);
    }
    return 0;   //Else it returns zero
}

/**
 * This function helps to check whether the given address is out of bounds in the 
 * simulated memory
 * 
 * @param i Helps to check if the address is in the memory
 * 
 * @return true if the given address is within the range of the simulated memory. 
 * @return false if the given address is not within the range of the simulated memory. 
 ********************************************************************************/

void registerfile::dump(const std::string &hdr) const
{
    cout << hdr << " x0" << right;

    int32_t i;

    for (i = 0; i <= 7; i++)
    {
        cout << " " << hex::to_hex32(registers.at(i));

        if(i == 3)
        {
            cout << " ";
        }
    }
    cout << endl;

    cout << hdr << " x8" << right;

    for (i = 8; i <= 15; i++)
    {
        cout << " " << hex::to_hex32(registers.at(i));

        if(i == 11)
        {
            cout << " ";
        }
    }
    cout << endl;

    cout << hdr << "x16" << right;

    for (i = 16; i <= 23; i++)
    {
        cout << " " << hex::to_hex32(registers.at(i));

        if(i == 19)
        {
            cout << " ";
        }
    }
    cout << endl;

    cout << hdr << "x24" << right;

    for(i = 24; i <= 31; i++)
    {
        cout << " " << hex::to_hex32(registers.at(i));

        if(i == 27)
        {
            cout << " ";
        }
    }
}
