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
#include <string>
#include <cassert>
#include "hex.h"
#include "registerfile.h"
#include "rv32i_decode.h"
#include "rv32i_hart.h"
#include "memory.h"

using namespace std;

/**
 * This function helps to reset the rv32i object and the registerfile.
 ********************************************************************************/

void rv32i_hart::reset() 
{
    //Set the pc register to zero.
    pc = 0;
    
    //Call regs.reset() to reset the register values.
    regs.reset();

    //Set the insn_counter to zero.
    insn_counter = 0;

    //Set the the halt flag to false.
    halt = false;

    //Set the the halt_reason to "none".
    halt_reason = "none";
}

/**
 * This function helps to dump the entire state of the hart.
 * 
 * @param hdr used to prefix each line printed by the given hdr string.
 ********************************************************************************/

void rv32i_hart::dump(const string &hdr) const
{
    //Making use of the regs member variable by calling regs.dump(hdr)
    regs.dump(hdr);
    
    //Prints the hdr once set
    cout << hdr;

    //Then add a dump of the PC register
    cout << setw(4) << right << endl << "pc " << hex::to_hex32(pc);
    cout << endl;
}

/**
 * This function helps  to tell the simulator to execute and instruction.
 * 
 * @param hdr used to prefix each line printed by the given hdr string.
 ********************************************************************************/

void rv32i_hart::tick(const string &hdr)
{
    //If the hart is halted 
    if(halt == true)
    {
        //Then return immediately without doing anything
        return;
    }

    //Increment the insn_counter variable (not the pc register.)
    insn_counter += 1;

    //If show_registers is true 
    if(show_registers == true)
    {
        //Then dump the state of the hart.
        dump(hdr);
    }

    //Fetch an instruction from the memory at the address in the pc register.
    uint32_t insn = mem.get32(pc);

    //If show_instructions is true then..
    if(show_instructions == true)
    {
        //..Print the hdr, the pc register (in hex), and the fetched instruction (in hex)
        cout << hdr << hex::to_hex32(pc) << ": " <<  hex::to_hex32(insn);
        cout << "  ";

        //..Call exec(insn, &std::cout) to execute the instruction and 
        //render the instruction and simulation details.
        exec(insn, &cout);
        cout << endl;
    }
    else
    {
        //Else, call exec(insn, nullptr) to execute the instruction without rendering anything.
        exec(insn, nullptr);
    }
}

/**
 * This function helps to execute the given RV32I instruction by making use 
 *  of the get_xxx() methods to extract the needed instruction fields to decode 
 *  the instruction and invoke the associated exec_xxx() helper function by using 
 *  the same sort of switch-logic from assignment 4.
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec(uint32_t insn, ostream* pos)
{
    //Initializing variable definitions
    uint32_t funct3 = get_funct3(insn);
    uint32_t funct7 = get_funct7(insn);
    
    //Switch statement with the value of the opcode instruction
    switch(get_opcode(insn))
    {
        default:                  exec_illegal_insn(insn, pos); return;
        case opcode_lui:          exec_lui(insn, pos); return; 
        case opcode_auipc:        exec_auipc(insn, pos); return;
        case opcode_jal:          exec_jal(insn, pos); return;
        case opcode_jalr:         exec_jalr(insn, pos); return;
        //Case where the opcode matches the instruction of the system
        case opcode_system:
            //If the instruction is equal to the ecall instruction
            if(insn == insn_ecall)
            {
                //Then it returns to the execute ecall instruction function
                exec_ecall(insn, pos); return;
            }
            //If the instruction is equal to the ebreak instruction
            if(insn == insn_ebreak)
            {
                //Then it returns to the execute ebreak instruction function
                exec_ebreak(insn, pos); return;
            }
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the system to the funct3 instruction of the system
            switch(funct3)
            {
                default:            exec_illegal_insn(insn, pos); return;
                case funct3_csrrs:  exec_csrrs(insn, pos); return;
            }
            assert (0 && "unrecognized funct3"); // impossible
        //Case where the opcode matches the instruction of the stype
        case opcode_stype:
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the stype to the funct3 instruction of the stype
            switch (funct3)
            {
                default:		    exec_illegal_insn(insn, pos); return;
                case funct3_sb:		exec_sb(insn, pos); return;
                case funct3_sh:		exec_sh(insn, pos); return;
                case funct3_sw:		exec_sw(insn, pos); return;
            }
            assert (0 && "unrecognized funct3"); // impossible
        //Case where the opcode matches the instruction of the btype
        case opcode_btype:
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the btype to the funct3 instruction of the btype
            switch(funct3)
            {
                default:            exec_illegal_insn(insn, pos);
                case funct3_beq:    exec_beq(insn, pos); return;
                case funct3_bne:    exec_bne(insn, pos); return;
                case funct3_blt:	exec_blt(insn, pos); return;
                case funct3_bge:	exec_bge(insn, pos); return;
                case funct3_bltu:	exec_bltu(insn, pos); return;
                case funct3_bgeu:	exec_bgeu(insn, pos); return;
            }
            assert(0 && "unrecognized funct3"); // impossible
        //Case where the opcode matches the instruction of the alu immediately
        case opcode_alu_imm:
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the alu immediate to the funct3 instruction of the alu immediate
            switch(funct3)
            {
                default:            exec_illegal_insn(insn, pos); return;
                case funct3_add:    exec_addi(insn, pos); return;
                case funct3_slt:	exec_slti(insn, pos); return;
                case funct3_sltu:	exec_sltiu(insn, pos); return;
                case funct3_xor:	exec_xori(insn, pos); return;
                case funct3_or:		exec_ori(insn, pos); return;
                case funct3_and:	exec_andi(insn, pos); return;
                case funct3_sll:	exec_slli(insn, pos); return;
                //Case where the opcode matches the instruction of the srx
                case funct3_srx:
                    //Switch statement with the value of the funct7 to differentiate between
                    //opcode of the srx to the funct7 instruction of the srx
                    switch(funct7)
                    {
                        default:            exec_illegal_insn(insn, pos); return;
                        case funct7_sra:    exec_srai(insn, pos); return;
                        case funct7_srl:    exec_srli(insn, pos); return;
                    }
                    assert(0 && "unrecognized funct7");  // impossible
            }
        //Case where the opcode matches the instruction of the load immediately  
        case opcode_load_imm:
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the load immediate to the funct3 instruction of the load immediate
            switch(funct3)
            {
                default:            exec_illegal_insn(insn, pos); return;
                case funct3_lb:     exec_lb(insn, pos); return;
                case funct3_lh:	    exec_lh(insn, pos); return;
                case funct3_lw:	    exec_lw(insn, pos); return;
                case funct3_lbu:	exec_lbu(insn, pos); return;
                case funct3_lhu:	exec_lhu(insn, pos); return;
            }
            assert(0 && "unrecognized funct3");  // impossible
        //Case where the opcode matches the instruction of the rtype
        case opcode_rtype:
            //Switch statement with the value of the funct3 to differentiate between
            //opcode of the rtype to the funct3 instruction of the rtype
            switch(funct3)
            {
                default:            exec_illegal_insn(insn, pos); return;
                //Case where the opcode matches the instruction of the add
                case funct3_add:
                    //Switch statement with the value of the funct7 to differentiate between
                    //opcode of the add to the funct7 instruction of the add   
                    switch(funct7)
                    {
                        default:            exec_illegal_insn(insn, pos); return;
                        case funct7_add:    exec_add(insn, pos); return;
                        case funct7_sub:    exec_sub(insn, pos); return;
                    }
                    assert(0 && "unrecognized funct7");  // impossible
                case funct3_sll:    exec_sll(insn, pos); return;
                case funct3_slt:    exec_slt(insn, pos); return;
                case funct3_sltu:   exec_sltu(insn, pos); return;
                case funct3_xor:    exec_xor(insn, pos); return;
                //Case where the opcode matches the instruction of the srx
                case funct3_srx:
                    //Switch statement with the value of the funct7 to differentiate between
                    //opcode of the srx to the funct7 instruction of the srx
                    switch(funct7)
                    {
                        default:            exec_illegal_insn(insn, pos); return;
                        case funct7_srl:    exec_srl(insn, pos); return;
                        case funct7_sra:    exec_sra(insn, pos); return;
                    }
                    assert(0 && "unrecognized funct7");  // impossible
                case funct3_or:     exec_or(insn, pos); return;
                case funct3_and:    exec_and(insn, pos); return;
            }
            assert(0 && "unrecognized funct3");  // impossible
    }
    assert(0 && "unrecognized opcode"); // It should be impossible to ever get here!
}

/**
 * This function helps to set the halt flag and, if the ostream* parameter 
 *  is not nullptr then use render_illegal_insn() to render the proper error 
 *  message by writing it to the pos output stream.
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_illegal_insn(uint32_t insn, ostream* pos)
{
    (void)insn;
    if (pos)
        *pos << render_illegal_insn(insn);
    halt = true;
    halt_reason = "Illegal instruction";
}

/**
 * This function helps to execute the lui instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lui(uint32_t insn, ostream* pos)
{
    if(pos)
    { 
        *pos << setw(instruction_width) << setfill(' ') << left << render_lui(insn);
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(get_imm_u(insn)); 
    }
    regs.set(get_rd(insn), get_imm_u(insn));
    pc += 4;
}

/**
 * This function helps to execute the aupic instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_auipc(uint32_t insn, ostream* pos)
{
    if(pos)
    { 
        *pos << setw(instruction_width) << setfill(' ') << left << render_auipc(insn);
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(pc)
        << " + " << hex::to_hex0x32(get_imm_u(insn)) << " = " << hex::to_hex0x32(pc + get_imm_u(insn)); 
    }
    regs.set(get_rd(insn), (pc + (get_imm_u(insn))));
    pc += 4;
}

/**
 * This function helps to execute the jal instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_jal(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill (' ') << left << render_jal(pc, insn);
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(pc + 4) << ",  pc = " <<
        hex::to_hex0x32(pc) << " + " << hex::to_hex0x32(get_imm_j(insn)) << " = " <<
        hex::to_hex0x32(pc + get_imm_j(insn));
    }
    regs.set(get_rd(insn), (pc + 4));
    pc = pc + get_imm_j(insn);
}

/**
 * This function helps to execute the jalr instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_jalr(uint32_t insn, ostream* pos)
{
    int32_t mask = 0xfffffffe;

    if(pos)
    { 
        *pos << setw(instruction_width) << setfill(' ') << left << render_jalr(insn);
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(pc + 4) << ",  pc = ("
        << hex::to_hex0x32(get_imm_i(insn)) << " + " << hex::to_hex0x32(regs.get(get_rs1(insn))) 
        << ") & 0xfffffffe = " << hex::to_hex0x32((regs.get(get_rs1(insn)) + get_imm_i(insn)) & mask);
    }
    regs.set(get_rd(insn), (pc + 4));
    pc = (regs.get(get_rs1(insn)) + get_imm_i(insn)) & mask;
}

/**
 * This function helps to execute the csrrs instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_csrrs(uint32_t insn, ostream *pos)
{
    int32_t mask = 0x00000fff;
    uint32_t imm_i = get_imm_i(insn) & mask;

    if(imm_i!= 0xf14 && regs.get(get_rs1(insn)) != 0)
    {
        halt = true;
        halt_reason = "Illegal CSR in CRRSS instruction";
    }
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_csrrx(insn, "csrrs");
        *pos << "// " << render_reg(get_rd(insn)) << " = " << mhartid; 
    }
    if(!halt)
    {
        regs.set(get_rd(insn), mhartid);
        pc += 4;
    }
}

/**
 * This function helps to execute the sb instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sb(uint32_t insn, ostream *pos)
{
    uint32_t addr = regs.get(get_rs1(insn)) + get_imm_s(insn);
    int32_t mask = 0x000000ff;

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_stype(insn, "sb");
        *pos << "// m8(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " << hex::to_hex0x32(get_imm_s(insn)) 
        << ") = " << hex::to_hex0x32(regs.get(get_rs2(insn)) & mask); 
    }
    mem.set8(addr, regs.get(get_rs2(insn)) & mask);
    pc += 4;
}

/**
 * This function helps to execute the sh instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sh(uint32_t insn, ostream *pos)
{
    int32_t mask = 0x0000ffff;

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_stype(insn, "sh");
        *pos << "// m16(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " << hex::to_hex0x32(get_imm_s(insn)) 
        << ") = " << hex::to_hex0x32(regs.get(get_rs2(insn)) & mask); 
    }
    mem.set16(regs.get(get_rs1(insn)) + get_imm_s(insn), regs.get(get_rs2(insn)) & mask);
    pc += 4;
}

/**
 * This function helps to execute the sw instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sw(uint32_t insn, ostream *pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_stype(insn, "sw");
        *pos << "// m32(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " << hex::to_hex0x32(get_imm_s(insn)) 
        << ") = " << hex::to_hex0x32(regs.get(get_rs2(insn))); 
    }
    mem.set32(regs.get(get_rs1(insn)) + get_imm_s(insn), regs.get(get_rs2(insn)));
    pc += 4;
}

/**
 * This function helps to execute the beq instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_beq(uint32_t insn, ostream *pos)
{
    int32_t value = pc + ((regs.get(get_rs1(insn)) == regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "beq");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " == " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the bne instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_bne(uint32_t insn, ostream* pos)
{
    int32_t value = pc + ((regs.get(get_rs1(insn)) != regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "bne");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " != " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the blt instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_blt(uint32_t insn, ostream* pos)
{
    int32_t value = pc + ((regs.get(get_rs1(insn)) < regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "blt");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " < " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the bge instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_bge(uint32_t insn, ostream* pos)
{
    int32_t value = pc + ((regs.get(get_rs1(insn)) >= regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "bge");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " >= " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the bltu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_bltu(uint32_t insn, ostream* pos)
{
    uint32_t value = pc + ((static_cast<uint32_t>(regs.get(get_rs1(insn))) < static_cast<uint32_t>(regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4));

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "bltu");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " <U " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the bgeu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_bgeu(uint32_t insn, ostream* pos)
{
    uint32_t value = pc + ((static_cast<uint32_t>(regs.get(get_rs1(insn))) >= static_cast<uint32_t>(regs.get(get_rs2(insn))) ? get_imm_b(insn) : 4));

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_btype(pc, insn , "bgeu");
        *pos << "// pc += (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " >=U "
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " ? " << hex::to_hex0x32(get_imm_b(insn)) 
        << " : 4) = " << hex::to_hex0x32(value);
    }
    pc = value;
}

/**
 * This function helps to execute the addi instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_addi(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "addi", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) + get_imm_i(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) + get_imm_i(insn));
    pc += 4;
}

/**
 * This function helps to execute the slti instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_slti(uint32_t insn, ostream* pos)
{
    int32_t value = (regs.get(get_rs1(insn)) < get_imm_i(insn)) ? 1 : 0;
    
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "slti", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " < " 
        << dec << get_imm_i(insn) << ") ? 1 : 0 = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the sltiu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sltiu(uint32_t insn, ostream* pos)
{
    uint32_t value = (static_cast<uint32_t>(regs.get(get_rs1(insn))) < static_cast<uint32_t>(get_imm_i(insn)) ? 1 : 0);
    
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "sltiu", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = (" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " <U " 
        << dec << get_imm_i(insn) << ") ? 1 : 0 = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the xori instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_xori(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "xori", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " ^ " 
        << hex::to_hex0x32(get_imm_i(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) ^ get_imm_i(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) ^ get_imm_i(insn));
    pc += 4;
}

/**
 * This function helps to execute the ori instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_ori(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "ori", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " | " 
        << hex::to_hex0x32(get_imm_i(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) | get_imm_i(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) | get_imm_i(insn));
    pc += 4;
}

/**
 * This function helps to execute the andi instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_andi(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "andi", get_imm_i(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " & " 
        << hex::to_hex0x32(get_imm_i(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) & get_imm_i(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) & get_imm_i(insn));
    pc += 4;
}

/**
 * This function helps to execute the slli instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_slli(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "slli", get_rs2(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " << " 
        << dec << get_rs2(insn) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) << get_rs2(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) << get_rs2(insn));
    pc += 4;
}

/**
 * This function helps to execute the srai instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_srai(uint32_t insn, ostream* pos)
{
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "srai", get_rs2(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " >> " 
        << dec << get_rs2(insn) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn)) >> get_rs2(insn));
    }
    regs.set(get_rd(insn), regs.get(get_rs1(insn)) >> get_rs2(insn));
    pc += 4;
}

/**
 * This function helps to execute the srli instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_srli(uint32_t insn, ostream* pos)
{
    int32_t mask = 0x80000000;
    int32_t mask1 = 0xfffffe1f;
    int32_t shiftmask = get_rs2(insn) & mask1;
    mask = ~((mask >> shiftmask) << 1);
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_alu(insn , "srli", get_rs2(insn));
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " >> " 
        << dec << get_rs2(insn) << " = " << hex::to_hex0x32((regs.get(get_rs1(insn)) >> get_rs2(insn)) & mask);
    }
    regs.set(get_rd(insn), (regs.get(get_rs1(insn)) >> get_rs2(insn)) & mask);
    pc += 4;
}

/**
 * This function helps to execute the lb instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lb(uint32_t insn, ostream* pos)
{
    int32_t addr = regs.get(get_rs1(insn)) + get_imm_i(insn);
    int32_t value = mem.get8(addr);
    int32_t mask = 0x00000080;
    int32_t mask1 = 0xffffff00;

    if(value & mask)
    {
        value |= mask1;
    }
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_load(insn , "lb");
        *pos << "// " << render_reg(get_rd(insn)) << " = sx(m8(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << ")) = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the lh instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lh(uint32_t insn, ostream* pos)
{
    int32_t addr = regs.get(get_rs1(insn)) + get_imm_i(insn);
    int32_t value = mem.get16(addr);
    int32_t mask = 0x00008000;
    int32_t mask1 = 0xffff0000;

    if(value & mask)
    {
        value |= mask1;
    }

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_load(insn , "lh");
        *pos << "// " << render_reg(get_rd(insn)) << " = sx(m16(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << ")) = " << hex::to_hex0x32(value);
    }

    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the lw instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lw(uint32_t insn, ostream* pos)
{
    int32_t addr = regs.get(get_rs1(insn)) + get_imm_i(insn);
    int32_t value = mem.get32(addr);
    int32_t mask = 0x80000000;
    int32_t mask1 = 0x00000000;

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_load(insn , "lw");
        *pos << "// " << render_reg(get_rd(insn)) << " = sx(m32(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << ")) = " << hex::to_hex0x32(value);
    }

    if(value & mask)
    {
        value |= mask1;
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the lbu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lbu(uint32_t insn, ostream* pos)
{
    int32_t addr = regs.get(get_rs1(insn)) + get_imm_i(insn);
    int32_t value = mem.get8(addr);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_load(insn , "lbu");
        *pos << "// " << render_reg(get_rd(insn)) << " = zx(m8(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << ")) = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the lhu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_lhu(uint32_t insn, ostream* pos)
{
    int32_t addr = regs.get(get_rs1(insn)) + get_imm_i(insn);
    int32_t value = mem.get16(addr);

    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_itype_load(insn , "lhu");
        *pos << "// " << render_reg(get_rd(insn)) << " = zx(m16(" << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(get_imm_i(insn)) << ")) = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the add instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_add(uint32_t insn, ostream* pos)
{
    int32_t value = regs.get(get_rs1(insn)) + regs.get(get_rs2(insn));
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_rtype(insn , "add");
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " + " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the sub instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sub(uint32_t insn, ostream* pos)
{
    int32_t value = regs.get(get_rs1(insn)) - regs.get(get_rs2(insn));
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_rtype(insn , "sub");
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " - " 
        << hex::to_hex0x32(regs.get(get_rs2(insn))) << " = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the sll instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sll(uint32_t insn, ostream* pos)
{
    int32_t value = regs.get(get_rs1(insn)) << (regs.get(get_rs2(insn)) % XLEN);
    if(pos)
    {
        *pos << setw(instruction_width) << setfill(' ') << left << render_rtype(insn , "sll");
        *pos << "// " << render_reg(get_rd(insn)) << " = " << hex::to_hex0x32(regs.get(get_rs1(insn))) << " << " 
        << dec << (regs.get(get_rs2(insn)) % XLEN) << " = " << hex::to_hex0x32(value);
    }
    regs.set(get_rd(insn), value);
    pc += 4;
}

/**
 * This function helps to execute the slt instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_slt(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = (regs.get(rs1) < regs.get(rs2)) ? 1 : 0;
    if (pos)
    {
        string s = render_rtype(insn, "slt");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(regs.get(rs1)) << " < " << hex::
        to_hex0x32(regs.get(rs2)) << ") ? 1 : 0 = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the sltu instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sltu(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = (regs.get(rs1) < regs.get(rs2)) ? 1 : 0;
    if (pos)
    {
        string s = render_rtype(insn, "sltu");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(regs.get(rs1)) << " <U " << hex::
        to_hex0x32(regs.get(rs2)) << ") ? 1 : 0 = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the xor instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_xor(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = (regs.get(rs1) ^ regs.get(rs2)) ? 1 : 0;
    if (pos)
    {
        string s = render_rtype(insn, "xor");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " ^ " << hex::
        to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the srl instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_srl(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = regs.get(get_rs1(insn));
    uint32_t rs2 = regs.get(get_rs2(insn));
    uint32_t shamt = rs2 % XLEN;

    int32_t val = (rs1 >> (shamt));
    if (pos)
    {
        string s = render_rtype(insn, "srl");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " >> " << shamt 
        << " = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the sra instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_sra(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = (regs.get(rs1) >> regs.get(rs2) % XLEN);
    if (pos)
    {
        string s = render_rtype(insn, "sra");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " >> " << dec 
        << (regs.get(rs2) % XLEN) << " = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the or instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_or(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = regs.get(rs1) | regs.get(rs2);
    if (pos)
    {
        string s = render_rtype(insn, "or");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " | " 
        << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the and instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_and(uint32_t insn, ostream* pos) 
{
    uint32_t rd = get_rd(insn);
    uint32_t rs1 = get_rs1(insn);
    uint32_t rs2 = get_rs2(insn);

    int32_t val = regs.get(rs1) & regs.get(rs2);
    if (pos)
    {
        string s = render_rtype(insn, "and");
        *pos << setw(instruction_width) << setfill(' ') << left << s;
        *pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " & " 
        << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
    }
    regs.set(rd, val);
    pc += 4;
}

/**
 * This function helps to execute the ecall instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_ecall(uint32_t insn, ostream* pos)
{
    if(pos)
    { 
        *pos << setw(instruction_width) << setfill(' ') << left << render_ecall(insn);
        *pos << "// HALT";
    }
    halt = true;
    halt_reason = "ECALL instruction";
}

/**
 * This function helps to execute the ebreak instruction
 * 
 * @param insn used for executing instructions
 * @param pos  used as an output stream
 ********************************************************************************/

void rv32i_hart::exec_ebreak(uint32_t insn, ostream* pos)
{
    if(pos)
    { 
        *pos << setw(instruction_width) << setfill(' ') << left << render_ebreak(insn);
        *pos << "// HALT";
    }
    halt = true;
    halt_reason = "EBREAK instruction";
}