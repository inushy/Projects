//******************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Anushka Verma (Z1911937)
//
// A Program That Simulates A Computer System Memory
//
//******************************************************************

#include "hex.h"

using namespace std;

/**
 * Returns a string with exactly 2 hex digits representing the 8 bits of the i argument.
 *
 * @param i Helps to display the unsigned int 8-bit integer as a two digit hex value
 **********************************************************************************************/

string hex::to_hex8(uint8_t i)
{
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);
    return os.str();

}

/**
 * Returns a string with exactly 8 hex digits representing the 32 bits of the i argument.
 *
 * @param i Helps to display the unsigned int 32-bit integer as a eight digit hex value
 **********************************************************************************************/

string hex::to_hex32(uint32_t i)
{
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(8) << i;
    return os.str();
}

/**
 * Returns a string beginning with 0x, followed by the 8 hex digits representing the 32 bits of the i argument
 *
 * @param i Helps to display the unsigned int 32-bit integer as 0x and a eight digit hex value
 **********************************************************************************************/

string hex::to_hex0x32(uint32_t i)
{
    return string("0x")+to_hex32(i);
}