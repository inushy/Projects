//******************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Anushka Verma (Z1911937)
//
// A Program That Simulates A Computer System Memory
//
//******************************************************************

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "hex.h"
#include "memory.h"

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
 * This function prints out the different results of the memory simulator
 * 
 * @param argc Description of the first parameter.
 * @param argvv Description of the second parameter.
 *
 * @return 0
 ********************************************************************************/

int main(int argc, char **argv)
{
    uint32_t memory_limit = 0x100; // default memory size is 0x100

    int opt;
    while((opt = getopt(argc, argv, "m:")) != -1)
    {
        switch(opt)
        {
            case 'm':
            {
                std::istringstream iss(optarg);
                iss >> std::hex >> memory_limit;
            }
            break;
            default:
                usage();
        }
    }

    if(optind >= argc)
    {
        usage(); //missing filename
    }
    memory mem(memory_limit);
    mem.dump();

    if(!mem.load_file(argv[optind]))
    {
        usage();
    }
    mem.dump(); 

    cout << mem.get_size() << endl;
    cout << hex::to_hex32(mem.get8(0)) << endl;
    cout << hex::to_hex32(mem.get16(0)) << endl;
    cout << hex::to_hex32(mem.get32(0)) << endl;
    cout << hex::to_hex0x32(mem.get8(0)) << endl;
    cout << hex::to_hex0x32(mem.get16(0)) << endl;
    cout << hex::to_hex0x32(mem.get32(0)) << endl;
    cout << hex::to_hex8(mem.get8(0)) << endl;
    cout << hex::to_hex8(mem.get16(0)) << endl;
    cout << hex::to_hex8(mem.get32(0)) << endl;
    cout << hex::to_hex0x32(mem.get32(0x1000)) << endl;

    mem.set8(0x10, 0x12);
    mem.set16(0x14, 0x1234);
    mem.set32(0x18, 0x87654321);

    cout << hex::to_hex0x32(mem.get8_sx(0x0f)) << endl;
    cout << hex::to_hex0x32(mem.get8_sx(0x7f)) << endl;
    cout << hex::to_hex0x32(mem.get8_sx(0x80)) << endl;
    cout << hex::to_hex0x32(mem.get8_sx(0xe3)) << endl;
    cout << hex::to_hex0x32(mem.get16_sx(0xe0)) << endl;
    cout << hex::to_hex0x32(mem.get32_sx(0xe0)) << endl;

    mem.dump();
    return 0;
}

