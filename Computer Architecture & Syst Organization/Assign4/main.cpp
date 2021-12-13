//******************************************************************
//
// CSCI 463 Assignment 4
//
// Author: Anushka Verma (Z1911937)
//
// Gaining a thorough understanding of the RV32I instruction set
//
//******************************************************************

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "hex.h"
#include "memory.h"
#include "rv32i_decode.h"

using namespace std;

/**
 * @note This function prints the error message and pattern to standard error
 * and terminates the program in the traditional manner
 ********************************************************************************/

static void usage()
{
    cerr << "Usage: rv32i [-m hex-m-size] in file" << endl;
    cerr << "     -m specify memory size (default = 0x100)" << endl;
    exit(1);
}

/**
 * This function will decode and print each instruction in a loop
 * 
 * @param mem variable used to print and decode the memory
 *
 ********************************************************************************/

static void disassemble(const memory &mem)
{
    //For every byte in the memory simulator, increment the memory address to the next insn
    for(unsigned i = 0; i < mem.get_size(); i+=4)
    {
        //Prints the memory address, instruction hex value, and the instruction mnemonic
        cout << hex::to_hex32(i) << ": " << hex::to_hex32(mem.get32(i)) << "  ";
        cout << rv32i_decode::decode(i, mem.get32(i));
        cout << endl;   //Prints a new line
    }
}

/**
 * This function loads and disassembles the RV32i instructions
 * 
 * @param argc Argument Count
 * @param argvv Argument Vector
 *
 * @return 0
 ********************************************************************************/

int main(int argc, char **argv)
{
    uint32_t memory_limit = 0x100;  //default memory size = 256 bytes
    int opt;
    while ((opt = getopt(argc, argv, "m:")) != -1)
    {
        switch (opt)
        {
            case 'm':
            {
                std::istringstream iss(optarg);
                iss >> std::hex >> memory_limit;
            }
            break;
            default: /* ’?’ */
            usage(); 
        }
    }
         if (optind >= argc)
             usage();    // missing filename
         memory mem(memory_limit);
         if (!mem.load_file(argv[optind]))
             usage();
         disassemble(mem);
         mem.dump();
    return 0; 
}

