//******************************************************************
//
// CSCI 463 Assignment 4
//
// Author: Anushka Verma (Z1911937)
//
// Gaining a thorough understanding of the RV32I instruction set
//
//******************************************************************
#ifndef HEX_H
#define HEX_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

/**
 * Class definition for the format of numbers as strings of hex
 ********************************************************************************/

class hex 
{
public:
    static string to_hex8(uint8_t i); 
    static string to_hex32(uint32_t i); 
    static string to_hex0x32(uint32_t i);
    static string to_hex0x20(uint32_t i);
    static string to_hex0x12(uint32_t i);
};

#endif 