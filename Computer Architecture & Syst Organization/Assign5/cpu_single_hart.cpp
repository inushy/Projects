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
#include "cpu_single_hart.h"

using namespace std;

/**
 * This function helps to work as a subclass of rv32i_hart that is then used to 
 *  represent a CPU with a single hart
 * 
 * @param exec_limit used as a max number of executed instructions
 ********************************************************************************/

void cpu_single_hart::run(uint64_t exec_limit)
{
    regs.set(2, mem.get_size());

    if(exec_limit == 0)
    {
        while(is_halted() == false)
        {
            tick();
        }
    }
    if(exec_limit != 0)
    {
        while(is_halted() == false && get_insn_counter() != exec_limit)
        {
            tick();
        }
    }
    if(is_halted() == true)
    {
        cout << "Execution terminated. Reason: " << get_halt_reason();
        cout << endl;
    }
    cout << get_insn_counter() << " instructions executed";
    cout << endl;
}