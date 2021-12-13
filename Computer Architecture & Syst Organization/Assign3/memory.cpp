//******************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Anushka Verma (Z1911937)
//
// A Program That Simulates A Computer System Memory
//
//******************************************************************
#include "memory.h"
#include "hex.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * This function helps to allocate and initialize the number of every bytes in the 
 * memory vector to 0xa5.
 * 
 * @param siz Helps to allocate the bytes in a memory vector
 ********************************************************************************/

memory::memory(uint32_t siz)
{
    siz = (siz+15)&0xfffffff0;  // round the length up, mod-16
    mem.resize(siz, 0xa5);
}

/**
 * This function helps to clear out the destructor
 ********************************************************************************/

memory::~memory()
{
    mem.clear();
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

bool memory::check_illegal(uint32_t i) const
{
    //if given address is out of bound then return true
    if(i > (mem.size() - 1))
    {
        cout << " WARNING: Address out of range: " << hex::to_hex0x32(i);  //print a warning message
        cout << endl;
        return true; // If the given address is within the range of valid addresses of the simulated memory then
    }
    else // If the given address is not within the range of valid addresses of the simulated memory then
    {
        return false;
    }
}

/**
 * This function helps to return the (rounded up) number of bytes in the 
 * simulated memory.
 * 
 * @return Returns the number of bytes in the simulated memory vector 
 ********************************************************************************/

uint32_t memory::get_size() const
{
    return mem.size();
}

/**
 * This function helps to check whether the given address is in the memory vector
 * 
 * @param addr Helps to check if the address is in the rage of the memory vector
 * 
 * @return addr if the given address is within the range of the simulated memory. 
 * @return 0 if the given address is not within the range of the simulated memory. 
 ********************************************************************************/

uint8_t memory::get8(uint32_t addr) const
{
    //if the given addr is in your mem by calling check_illegal()
    if(check_illegal(addr) == 0)
    {
        //If addr is in the valid range then return the value of the byte 
        //from your simulated memory at the given address.
        return mem.at(addr);
    }
    else
    {
        //If addr is not in the valid range then return zero to the caller
        return 0;
    }
}

/**
 * This function helps to call our get8() function twice in order to get two bytes 
 * and then combine them in the little-endian order to create a 16-bit return value.
 * 
 * @param addr Helps to call our get8() function to combine them in the little-endian
 *    order
 * 
 * @return The 16-bit value
 ********************************************************************************/

uint16_t memory::get16(uint32_t addr) const
{
    //Variables to call the get8() twice for the little-endian 16-bit order
    uint16_t func = get8(addr); 
    uint16_t funct = get8(addr + 1);

    //The little-endian convertion
    uint16_t LE = (funct << 8| func);

    return LE;
}

/**
 * This function helps to call our get16() function twice in order to get two bytes 
 * and then combine them in the little-endian order to create a 32-bit return value.
 * 
 * @param addr Helps to call our get16() function to combine them in the little-endian
 *    order
 * 
 * @return The 32-bit value
 ********************************************************************************/

uint32_t memory::get32(uint32_t addr) const
{
    //Variables to call the get16() twice for the little-endian 32-bit order
    uint32_t func = get16(addr);
    uint32_t funct = get16(addr + 2);

    //The little-endian convertion
    uint32_t LE = (funct << 16| func);

    return LE;
}

/**
 * This function helps to call get8() and then return the sign-extended value 
 * of the byte as a 32-bit signed integer.
 * 
 * @param addr Helps to call our get8() function
 * 
 * @return Helps to return the signs's extended value
 ********************************************************************************/

int32_t memory::get8_sx(uint32_t addr) const
{
    int32_t func = get8(addr);  //Variable to call the get8() once for the 32-bit signed integer
    int32_t hvalue = 0x00000080; //Variable to access the hex value needed 
    int32_t mask = 0xffffff00;  //Variable to access the mask value needed

    return func | (func & hvalue ? mask : 0);   //Returns the sign-extended value
}

/**
 * This function helps to call get16() and then return the sign-extended value 
 * of the byte as a 32-bit signed integer.
 * 
 * @param addr Helps to call our get16() function
 * 
 * @return Helps to return the signs's extended value
 ********************************************************************************/

int32_t memory::get16_sx(uint32_t addr) const
{
    int32_t func = get16(addr); //Variable to call the get16() once for the 32-bit signed integer
    int32_t hvalue = 0x00000080; //Variable to access the hex value needed 
    int32_t mask = 0xffffff00;  //Variable to access the mask value needed

    return func | (func & hvalue ? mask : 0);   //Returns the sign-extended value
}

/**
 * This function helps to call get32() and then return the value as a 
 * 32-bit signed integer.
 * 
 * @param addr Helps to call our get32() function
 * 
 * @return Helps to return the signs's extended value
 ********************************************************************************/

int32_t memory::get32_sx(uint32_t addr) const
{
    return get32(addr); //Returns the sign-extended value
}

/**
 * This function helps to call check_illegal() to verify the the addr argument 
 * is valid. If addr is valid then set the byte in the simulated memory at that 
 * address to the given val.
 * 
 * @param addr If the check is legal, then the given address stores the 
 *    value within the addr.
 * @param val If the check is legal, then the given address stores the 
 *    value within the memory vector.
 * 
 * @return If addr is not valid then discard the data and return to the caller.
 * 
 * @note That this, and the constructor, are the only code that will 
 *    ever write values into the mem vector.
 ********************************************************************************/

void memory::set8(uint32_t addr, uint8_t val)
{
    //If addr is valid then set the byte in the 
    //simulated memory at that address to the given val.
    if(check_illegal(addr) == 0)
    {
        //the only code that will ever write values into the mem vector.
        mem.at(addr) = val;
    }
    else
    {
        return; //Returns to the caller
    }
}

/**
 * This function helps to call set8() twice to store the given val in 
 * little-endian order into the simulated memory starting at the address 
 * given in the addr argument.
 * 
 * @param addr If the check is legal, then the given address stores the 
 *    value within the addr.
 * @param val If the check is legal, then the given address stores the 
 *    value within the memory vector.
 ********************************************************************************/

void memory::set16(uint32_t addr, uint16_t val)
{
    uint8_t result = (val & 0xff00) >> 8; //Left bit
    uint8_t result1 = (val & 0x00ff); //Right bit

    set8(addr, result); //Sets left bit
    set8(addr + 1, result1); //Sets right bit
}

/**
 * This function helps to call set16() twice to store the given val in 
 * little-endian order into the simulated memory starting at the address 
 * given in the addr argument.
 * 
 * @param addr If the check is legal, then the given address stores the 
 *    value within the addr.
 * @param val If the check is legal, then the given address stores the 
 *    value within the memory vector.
 ********************************************************************************/

void memory::set32(uint32_t addr, uint32_t val)
{
    uint16_t result = (val & 0xffff0000) >> 16; //Left bit
    uint16_t result1 = (val & 0x0000ffff);  //Right bit


    set16(addr, result);    //Sets left bit
    set16(addr + 2, result1);   //Sets right bit
}

/**
 * This function helps to Dump the entire contents of our simulated memory 
 * in hex with the corresponding ASCII characters on the right exactly, 
 * space-for-space format.
 ********************************************************************************/

void memory::dump() const
{
    string val = "";
    int count = 0;

    for(unsigned int i = 0; i < mem.size(); i++)    //For every byte in the memory simulator, format the dump.
    {
        if(count % 16 == 0)
        {
            cout << hex::to_hex32(count) << ": ";
        }
        cout << hex::to_hex8(mem[i]) << " ";
        count++;
        if(count % 8 == 0 && count != 0)
        {
            cout << " ";
        }
        //In order to format the ASCII part of the dump lines, 
        //fetch a byte from the memory and then use isprint(3) 
        //to determine if you are to show an ASCII character or a 
        //dot (.) when the byte does not have a valid printable value

        //Leaves the character to be printed in the ASCII portion of the 
        //dump in the ch variable.
        uint8_t ch = get8(i);
        ch = isprint(ch) ? ch : '.'; 
        val += ch;
        if(val.length() == 16)
        {
            cout << "*" << val << "*" << endl;
            val.clear();
        }
    }
}

/**
 * This function helps to open the file to binary mode and read its contents into our
 * simulated memory.
 * 
 * @param fname The name of the file being read
 * 
 * @return false when the program is too big and can't open.
 * @return true when the program can be opened.
 * 
 ********************************************************************************/

bool memory::load_file(const std::string &fname)
{
    std::ifstream infile(fname, std::ios::in|std::ios::binary); //Opens the file
    if(infile.is_open() == true)
    {
        uint8_t i;
        infile >> std::noskipws;       //Used to read the whitespace in the program
        for (uint32_t addr = 0; infile >> i; ++addr)    //For every byte in the file, then check whether the file fits in the memory
        {
            if(check_illegal(addr) == 1)
            {
                cerr << "Program too big." << endl; //If not, then print error message
                infile.close();
                return false;
            }
            mem.at(addr) = i;   //Else, set the byte in the memory
        }

        infile.close();  //Closes the file
        return true;
    }
    cerr << "Can’t open file " << fname << "for reading." << endl;  //Else, print error message
    return false;
}