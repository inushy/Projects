//******************************************************************
//
// CSCI 463 Assignment 4
//
// Author: Anushka Verma (Z1911937)
//
// Gaining a thorough understanding of the RV32I instruction set
//
//******************************************************************
#include "memory.h"
#include "hex.h"
#include <iostream>
#include <string>
#include "rv32i_decode.h"
#include <cassert>

using namespace std;

/**
 * This function helps to decode by calling the correct instructions
 * 
 * @param addr Address parameter instruction to help decode
 * @param insn Instruction parameter that gets decoded 
 ********************************************************************************/
string rv32i_decode::decode(uint32_t addr, uint32_t insn)
{
    //Initializing variable definitions
    uint32_t funct3 = get_funct3(insn);
    uint32_t funct7 = get_funct7(insn);

    //Switch statement with the value of the opcode instruction
    switch(get_opcode(insn))
    {
      default:            return render_illegal_insn(insn);
      case opcode_lui:    return render_lui(insn);
      case opcode_auipc:  return render_auipc(insn);
      case opcode_jal:    return render_jal(addr, insn);
      case opcode_jalr:   return render_jalr(insn);
      //Case where the opcode matches the instruction of the system
      case opcode_system:
        //If the instruction is equal to the ecall instruction
        if(insn == insn_ecall)
        {
            //Then it returns to the render ecall instruction function
            return render_ecall(insn);
        }
        //If the instruction is equal to the ebreak instruction
        if(insn == insn_ebreak)
        {
            //Then it returns to the render ebreak instruction function
            return render_ebreak(insn);
        }
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the system to the funct3 instruction of the system
        switch(funct3)
        {
            default:            return render_illegal_insn(insn);
            case funct3_csrrw:  return render_csrrx(insn, "csrrw");
            case funct3_csrrs:  return render_csrrx(insn, "csrrs");
            case funct3_csrrc:  return render_csrrx(insn, "csrrc");
            case funct3_csrrwi:	return render_csrrxi(insn, "csrrwi");
	        case funct3_csrrsi:	return render_csrrxi(insn, "csrrsi");
	        case funct3_csrrci:	return render_csrrxi(insn, "csrrci");
        }
        assert (0 && "unrecognized funct3"); // impossible

      //Case where the opcode matches the instruction of the stype
      case opcode_stype:
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the stype to the funct3 instruction of the stype
        switch (funct3)
        {
            default:		    return render_illegal_insn(insn);
            case funct3_sb:		return render_stype(insn, "sb");
            case funct3_sh:		return render_stype(insn, "sh");
            case funct3_sw:		return render_stype(insn, "sw");
        }
        assert (0 && "unrecognized funct3"); // impossible

      //Case where the opcode matches the instruction of the btype
      case opcode_btype:
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the btype to the funct3 instruction of the btype
        switch(funct3)
        {
            default:            return render_illegal_insn(insn);
            case funct3_beq:    return render_btype(addr, insn, "beq");
            case funct3_bne:    return render_btype(addr, insn, "bne");
            case funct3_blt:	return render_btype(addr, insn, "blt");
            case funct3_bge:	return render_btype(addr, insn, "bge");
            case funct3_bltu:	return render_btype(addr, insn, "bltu");
            case funct3_bgeu:	return render_btype(addr, insn, "bgeu");
        }
        assert(0 && "unrecognized funct3"); // impossible

      //Case where the opcode matches the instruction of the alu immediately
      case opcode_alu_imm:
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the alu immediate to the funct3 instruction of the alu immediate
        switch(funct3)
        {
            default:            return render_illegal_insn(insn);
            case funct3_add:    return render_itype_alu(insn, "addi", get_imm_i(insn));
            case funct3_slt:	return render_itype_alu(insn, "slti", get_imm_i(insn));
            case funct3_sltu:	return render_itype_alu(insn, "sltiu", get_imm_i(insn));
            case funct3_xor:	return render_itype_alu(insn, "xori", get_imm_i(insn));
            case funct3_or:		return render_itype_alu(insn, "ori", get_imm_i(insn));
            case funct3_and:	return render_itype_alu(insn, "andi", get_imm_i(insn));
            case funct3_sll:	return render_itype_alu(insn, "slli", get_imm_i(insn)%XLEN);
            //Case where the opcode matches the instruction of the srx
            case funct3_srx:
                //Switch statement with the value of the funct7 to differentiate between
                //opcode of the srx to the funct7 instruction of the srx
                switch(funct7)
                {
                    default:            return render_illegal_insn(insn);
                    case funct7_sra:    return render_itype_alu(insn, "srai", get_imm_i(insn)%XLEN);
                    case funct7_srl:    return render_itype_alu(insn, "srli", get_imm_i(insn)%XLEN);
                }
                assert(0 && "unrecognized funct7");  // impossible
        }
      //Case where the opcode matches the instruction of the load immediately  
      case opcode_load_imm:
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the load immediate to the funct3 instruction of the load immediate
        switch(funct3)
        {
            default:            return render_illegal_insn(insn);
            case funct3_lb:     return render_itype_load(insn, "lb");
            case funct3_lh:	    return render_itype_load(insn, "lh");
            case funct3_lw:	    return render_itype_load(insn, "lw");
            case funct3_lbu:	return render_itype_load(insn, "lbu");
            case funct3_lhu:	return render_itype_load(insn, "lhu");
        }
        assert(0 && "unrecognized funct3");  // impossible

      //Case where the opcode matches the instruction of the rtype
      case opcode_rtype:
        //Switch statement with the value of the funct3 to differentiate between
        //opcode of the rtype to the funct3 instruction of the rtype
        switch(funct3)
        {
            default:            return render_illegal_insn(insn);
            //Case where the opcode matches the instruction of the add
            case funct3_add:
                //Switch statement with the value of the funct7 to differentiate between
                //opcode of the add to the funct7 instruction of the add   
                switch(funct7)
                {
                    default:            return render_illegal_insn(insn);
                    case funct7_add:    return render_rtype(insn, "add");
                    case funct7_sub:    return render_rtype(insn, "sub");
                }
                assert(0 && "unrecognized funct7");  // impossible
            case funct3_sll:    return  render_rtype(insn, "sll");
            case funct3_slt:    return  render_rtype(insn, "slt");
            case funct3_sltu:   return  render_rtype(insn, "sltu");
            case funct3_xor:    return  render_rtype(insn, "xor");
            //Case where the opcode matches the instruction of the srx
            case funct3_srx:
                //Switch statement with the value of the funct7 to differentiate between
                //opcode of the srx to the funct7 instruction of the srx
                switch(funct7)
                {
                    default:            return render_illegal_insn(insn);
                    case funct7_srl:    return render_rtype(insn, "srl");
                    case funct7_sra:    return render_rtype(insn, "sra");
                }
                assert(0 && "unrecognized funct7");  // impossible
            case funct3_or:     return  render_rtype(insn, "or");
            case funct3_and:    return  render_rtype(insn, "and");
        }
        assert(0 && "unrecognized funct3");  // impossible
    }
    assert(0 && "unrecognized opcode"); // It should be impossible to ever get here!
}

/**
 * This function helps to allocate and initialize the number of every bytes in the 
 * memory vector to 0xa5.
 * 
 * @param insn Instruction parameter used to try and be rendered
 * 
 * @return An error message when there is an unimplemented instruction
 ********************************************************************************/

string rv32i_decode::render_illegal_insn(uint32_t insn)
{
    (void)insn;
    return "ERROR: UNIMPLEMENTED INSTRUCTION";
}

/**
 * This function helps to decode the lui instruction
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_lui(uint32_t insn)
{
    //Initializing variable definitions
    uint32_t rd = get_rd(insn);
    int32_t imm_u = get_imm_u(insn);
    
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, and the imm_u value
    ostringstream os;
    os << render_mnemonic("lui") << render_reg(rd) << ","
       << hex::to_hex0x20((imm_u >> 12)&0x0fffff);
    return os.str();    //Returns the string
}

/**
 * This function helps to decode the auipc instruction
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_auipc(uint32_t insn)
{
    //Initializing variable definitions
    uint32_t rd = get_rd(insn);
    int32_t imm_u = get_imm_u(insn);

    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, and the imm_u value
    ostringstream os;
    os << render_mnemonic("auipc") << render_reg(rd) << ","
       << hex::to_hex0x20((imm_u >> 12)&0x0fffff);
    return os.str();    //Returns the string
}

/**
 * This function helps to decode the jal instruction
 * 
 * @param addr Address parameter instruction to help decode
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_jal(uint32_t addr, uint32_t insn)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, and the address + the imm_j value
    ostringstream os;
    os << render_mnemonic("jal") << render_reg(get_rd(insn)) << ","
       << hex::to_hex0x32(addr + get_imm_j(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode the jalr instruction
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_jalr(uint32_t insn)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the rs1 value, and the imm_i value
    ostringstream os;
    os << render_mnemonic("jalr") << render_reg(get_rd(insn)) << ","
       << render_base_disp(get_rs1(insn), get_imm_i(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to render the mnemonic with the proper space padding 
 * on right side to make it mnemonic_width characters long.
 * 
 * @param mnemonic Used to render with the padding on the right side
 * 
 * @return The string used to render the right spaced padded mnemonic
 ********************************************************************************/

string rv32i_decode::render_mnemonic(const string &mnemonic)
{
    //If the mnemonic is equal to ecall or ebreak
    if( mnemonic =="ecall" ||mnemonic == "ebreak")
    {
        //Then return the mnemonic
        return mnemonic;
    }

    //Renders the instruction by setting the string to 
    //print spaces
    ostringstream os;
    os << setfill (' ') << left << setw(mnemonic_width) << mnemonic;
    return os.str();    //Returns the string
}

/**
 * This function helps to render the operands of the form
 * 
 * @param reg Register parameter instruction to help render
 * @param imm Immediate instruction parameter that gets rendered
 * 
 * @return The string used to render the right spaced padded mnemonic
 ********************************************************************************/

string rv32i_decode::render_base_disp(uint32_t reg, int32_t imm)
{
    //Renders the instruction by setting the string to 
    //format the parenthesis in the register
    ostringstream os;
    os << imm << "(" << render_reg(reg) << ")";
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the btypes instructions
 * 
 * @param addr Address parameter instruction to help decode
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_btype(uint32_t addr, uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rs1 value, the rs2 value, and the address + imm_b value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rs1(insn)) << ","
        << render_reg(get_rs2(insn)) << "," << hex::to_hex0x32(addr + get_imm_b(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the csrrx instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_csrrx(uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the imm_i value, and the rs1 value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rd(insn)) << ","
        << hex::to_hex0x12(get_imm_i(insn)) << "," << render_reg(get_rs1(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the csrrxi instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_csrrxi(uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the imm_i value, and the rs1 value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rd(insn)) << ","
        << hex::to_hex0x12(get_imm_i(insn)) << "," << get_rs1(insn);
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the stype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_stype(uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rs2 value, the rs1 value, and the imm_s value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rs2(insn)) << ","
        << render_base_disp(get_rs1(insn), get_imm_s(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the alu instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * @param imm_i Immediate instruction parameter that gets rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the rs1 value, and the imm_i value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rd(insn)) << ","
        << render_reg(get_rs1(insn)) << "," << imm_i;
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the itype load instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_itype_load(uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the rs1 value, and the imm_i value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rd(insn)) << ","
        << render_base_disp(get_rs1(insn), get_imm_i(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the rtype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * @param mnemonic The instruction that is used to be rendered
 * 
 * @return The string used to decode the instruction
 ********************************************************************************/

string rv32i_decode::render_rtype(uint32_t insn, const char *mnemonic)
{
    //Decodes the instruction by setting the string to 
    //print it by Name, rd value, the rs1 value, and the rs2 value
    ostringstream os;
    os << render_mnemonic(mnemonic) << render_reg(get_rd(insn)) << ","
        << render_reg(get_rs1(insn)) <<  "," << render_reg(get_rs2(insn));
    return os.str();    //Returns the string
}

/**
 * This function helps to decode all the rtype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 7 last bit instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_opcode(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0x0000007f;
    return (insn & mask);   //Returns the last 7 bits which basically is the opcode field
}

/**
 * This function helps to decode all the rtype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 7-11 bit range instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_rd(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0x00000f80;
    return (insn & mask) >> 7;  //Returns 7-11 bit range which basically is the opcode field
}

/**
 * This function helps to decode all the rtype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 12-14 bit range instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_funct3(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0x00007000;
    return (insn & mask) >> 12; //Returns 12-14 bit range which basically is the opcode field
}

/**
 * This function helps to decode all the rtype instructions
 * 
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 25-31 bit range instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_funct7(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0xfe000000;
    return (insn & mask) >> 25; //Returns 25-31 bit range which basically is the opcode field
}

/**
 * This function helps to Extract and return the rs1 field from the given 
 * instruction as an integer value from 0 to 31
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 15-19 bit range instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_rs1(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0x000f8000;
    return (insn & mask) >> 15; //Returns 15-19 bit range which basically is the rs1 field
}

/**
 * This function helps to Extract and return the rs1 field from the given 
 * instruction as an integer value from 0 to 31
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The 20-24 bit range instruction
 ********************************************************************************/

uint32_t rv32i_decode::get_rs2(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0x01f00000;
    return (insn & mask) >> 20; //Returns 20-24 bit range which basically is the rs2 field
}

/**
 * This function helps to render the register with the given int
 *
 * @param r Is the register name used to render
 * 
 * @return The string of the register name
 ********************************************************************************/

string rv32i_decode::render_reg(int r)
{
    //Renders the instruction by setting the string to 
    //print an 'x' before the register name
    ostringstream os;
    os << "x" << r;
    return os.str();    //Returns the string
}

/**
 * This function helps to Extract and return the imm_u field 
 * from the given instruction as a 32-bit signed integer as shown in RVALP
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

int32_t rv32i_decode::get_imm_u(uint32_t insn)
{
    //Initializing a mask
    int32_t mask = 0xfffff000;
    return (insn & mask);   //Returns the instruction bits which basically is the imm_u field
}

/**
 * This function helps to Extract and return the imm_i field 
 * from the given instruction as a 32-bit signed integer as shown in RVALP
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

int32_t rv32i_decode::get_imm_i(uint32_t insn)
{
    //Initializing masks
    int32_t mask1 = 0x80000000;
    int32_t mask2 = 0x7ff00000;
    int32_t mask3 = 0xfffff000;
    int32_t imm_i = (insn & mask1) >> (31 -11);
    imm_i |= (insn & mask2) >> (20 - 0); //Shifts the selected bit values to the right from 20 - 0
    if(insn & mask1)
    {
        imm_i |= mask3;     //Sign - extend the left
    }
    return imm_i;
}

/**
 * This function helps to Extract and return the imm_s field from 
 * the given instruction
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

int32_t rv32i_decode::get_imm_s(uint32_t insn)
{
    int32_t imm_s = (insn & 0xfe000000) >> (25-5);  //Shifts the selected bit values to the right from 25 - 5
    imm_s |= (insn & 0x00000f80) >> (7-0);  //Shifts the selected bit values to the right from 7 - 0
    if (insn & 0x80000000)
        imm_s |= 0xfffff000;    // sign-extend the left
    return imm_s;
}

/**
 * This function helps to Extract and return the imm_b field 
 * from the given instruction as a 32-bit signed integer as
 * shown in RVALP
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

int32_t rv32i_decode::get_imm_b(uint32_t insn)
{
    //Initializing a variable called imm_b
    int32_t imm_b;
    //Initializing mask1
    int32_t mask1 = 0x00000f00;
    imm_b = (insn & mask1) >> (8 - 1);  //Shifts the selected bit values to the right from 8 - 1
    //Initializing mask2
    int32_t mask2 = 0x7e000000;
    imm_b |= (insn & mask2) >> (30 - 10);   //Shifts the selected bit values to the right from 30 - 10
    //Initializing mask3
    int32_t mask3 = 0x00000080;
    imm_b |= (insn & mask3) << (11 - 7);    //Shifts the selected bit values to the left from 11 - 7
    //Initializing mask4
    int32_t mask4 = 0x80000000;
    imm_b |= (insn & mask4) >> (31 - 12);   //Shifts the selected bit values to the right from 31 - 12
    
    if (insn & mask4)
        imm_b |= 0xfffff000;    //Sign - extend the left
    return imm_b;
    
}

/**
 * This function helps to Extract and return the imm_j field 
 * from the given instruction as a 32-bit signed integer as
 * shown in RVALP
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

int32_t rv32i_decode::get_imm_j(uint32_t insn)
{
    //Initializing mask
    int32_t mask = 0x7fe00000;
    int32_t imm_j = insn & mask;

    imm_j = imm_j >> (30-10);   //Shifts the selected bit values to the right from 30 - 10

    //Initializing mask1
    int32_t mask1 = 0x00100000;
    int32_t i = insn & mask1;

    i = i >> (20-11);   //Shifts the selected bit values to the right from 20 - 11
    i |= i | imm_j;

    //Initializing mask2
    int32_t mask2 = 0x000ff000;
    int32_t im = insn & mask2;

    int32_t imm_j1 = im |= im | i;

    if (insn & 0x80000000)
        imm_j1 |= 0xfff00000;    // sign-extend the left

    return imm_j1;
}

/**
 * This function helps to return the ecall when ecall insn exist
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

string rv32i_decode::render_ecall(uint32_t insn)
{
    //String os calls onto the ecall 
    ostringstream os;
    os << render_mnemonic("ecall");
    return os.str();    //Returns string
}

/**
 * This function helps to return the ecall when ebreak insn exist
 *
 * @param insn Instruction parameter used to be rendered
 * 
 * @return The instruction bits 
 ********************************************************************************/

string rv32i_decode::render_ebreak(uint32_t insn)
{
    //String os calls onto the ebreak
    ostringstream os;
    os << render_mnemonic("ebreak");
    return os.str();   //Returns string
}