//******************************************************************
//
// CSCI 463 Assignment 5
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
#include "registerfile.h"
#include "cpu_single_hart.h"
#include "rv32i_hart.h"

using namespace std;

/**
 * @note This function prints the error message and pattern to standard error
 * and terminates the program in the traditional manner
 ********************************************************************************/

static void usage()
{
    cerr << "Usage: rv32i [-d] [-i] [-r] [-z] [-l exec-limit] [-m hex-mem-size] infile" << endl;
    cerr << "     -d show disassembly before program execution" << endl;
    cerr << "     -i show instruction printing during execution" << endl;
    cerr << "     -l maximum number of instructions to exec" << endl;
    cerr << "     -m specify memory size (default = 0x100)" << endl;
    cerr << "     -r show register printing during execution" << endl;
    cerr << "     -z show a dump of the regs & memory after simulation" << endl;
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
    bool dissemble_insn = false;
    bool show_insn = false;
    bool reg_insn = false;
    bool dump_insn = false;
    uint64_t exec_limit = 0;
    while ((opt = getopt(argc, argv, "dil:m:rz")) != -1)
    {
        switch (opt)
        {
            case 'd':
            {
                dissemble_insn = true;
            }
			break;
            case 'i':
            {
                show_insn = true;
            }
            break;
            case 'l':
            {
                std::istringstream iss(optarg);
                iss >> exec_limit;
            }
            break;
            case 'm':
            {
                std::istringstream iss(optarg);
                iss >> std::hex >> memory_limit;
            }
            break;
            case 'r':
            {
                reg_insn = true;
            }
            break;
            case 'z':
            {
                dump_insn = true;
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
         if(dissemble_insn == true)
         {
            disassemble(mem);
         }
         cpu_single_hart cpu(mem);
         cpu.reset();
         if(show_insn == true)
         {
            cpu.set_show_instructions(true);
         }
         if(reg_insn == true)
         {
            cpu.set_show_registers(true);
         } 
            cpu.run(exec_limit);
         if(dump_insn == true)
         {
             cpu.dump();
             mem.dump();
         } 

    return 0; 
}

