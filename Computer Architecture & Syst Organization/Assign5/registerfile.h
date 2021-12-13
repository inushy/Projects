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

#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "hex.h"
#include <stdint.h>

using namespace std;

/**
 * Class definition for the format of registerfile functions
 ********************************************************************************/

class registerfile
{
    public:
        void reset();
        void set(uint32_t r, int32_t val);
        int32_t get(uint32_t r) const;
        void dump(const string &hdr) const;
    private:
        vector<int32_t> registers;
};

#endif