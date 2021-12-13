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

#ifndef CPU_SINGLE_HART_H
#define CPU_SINGLE_HART_H

#include "rv32i_hart.h"

using namespace std;

/**
 * Class definition for the run functions of CPU
 ********************************************************************************/

class cpu_single_hart : public rv32i_hart
{
    public:
        cpu_single_hart(memory &mem) : rv32i_hart(mem){}
        void run(uint64_t exec_limit);
};

#endif