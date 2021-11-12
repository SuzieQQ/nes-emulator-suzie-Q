#include"Typedef.h"
#include "Cpu.h"

namespace olc6502

{

Cpu::Cpu() //Costructor
{

for (int i = 0; i < 256; i++)

Table[0x00] = INSTRUCTION {"BRK", &Cpu::BRK, &Cpu::IMP, 7};
Table[0x10] = INSTRUCTION {"BPL", &Cpu::BPL, &Cpu::REL, 2};
Table[0x20] = INSTRUCTION {"JSR", &Cpu::JSR, &Cpu::ABS, 6};
Table[0x30] = INSTRUCTION {"BMI", &Cpu::BMI, &Cpu::REL, 2};
Table[0x40] = INSTRUCTION {"RTI", &Cpu::RTI, &Cpu::IMP, 6};
Table[0x50] = INSTRUCTION {"BVC", &Cpu::BVC, &Cpu::REL, 2};
Table[0x60] = INSTRUCTION {"RTS", &Cpu::RTS, &Cpu::IMP, 6};
/*
Table[0x70] = INSTRUCTION {"BVS", &Cpu::BVS, &Cpu::REL, 2};
Table[0x90] = INSTRUCTION {"BCC", &Cpu::BCC, &Cpu::REL, 2};
Table[0xA0] = INSTRUCTION {"LDY#",&Cpu::LDY, &Cpu::IMM, 2};
Table[0xB0] = INSTRUCTION {"BCS", &Cpu::BCS, &Cpu::REL, 2};
Table[0xC0] = INSTRUCTION {"CPY#",&Cpu::CPY, &Cpu::IMM, 2};
Table[0xD0] = INSTRUCTION {"BNE", &Cpu::BNE, &Cpu::REL, 2};
Table[0xE0] = INSTRUCTION {"CPX", &Cpu::CPX, &Cpu::IMM, 2};
Table[0xF0] = INSTRUCTION {"BEQ", &Cpu::BEQ, &Cpu::REL, 2};
Table[0x01] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::INX, 6};
Table[0x11] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::INY, 5};
Table[0x21] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::INX, 6};
Table[0x31] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::INY, 5};
Table[0x41] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::INX, 6};
Table[0x51] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::INY, 5};
Table[0x61] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::INX, 6};
Table[0x71] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::INY, 5};
Table[0x81] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::INX, 6};
Table[0x91] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::INY, 6};
Table[0xA1] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::INX, 6};
Table[0xB1] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::INY, 5};
Table[0xC1] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::INX, 6};
Table[0xD1] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::INY, 5};
Table[0xE1] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::INX, 6};
Table[0xF1] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::INY, 5};
Table[0xA2] = INSTRUCTION {"LDX", &Cpu::LDX, &Cpu::IMM, 2};
Table[0x24] = INSTRUCTION {"BIT", &Cpu::BIT, &Cpu::ZP0, 3};
Table[0x84] = INSTRUCTION {"STY", &Cpu::STY, &Cpu::ZP0, 3};
Table[0x94] = INSTRUCTION {"STY", &Cpu::STY, &Cpu::ZPX, 4};
Table[0xA4] = INSTRUCTION {"LDY", &Cpu::LDY, &Cpu::ZP0, 3};
Table[0xB4] = INSTRUCTION {"LDY", &Cpu::LDY, &Cpu::ZPX, 4};
Table[0xC4] = INSTRUCTION {"CPY", &Cpu::CPY, &Cpu::ZP0, 3};
Table[0xE4] = INSTRUCTION {"CPX", &Cpu::CPX, &Cpu::ZP0, 3};
Table[0x05] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::ZP0, 3};
Table[0x15] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::ZPX, 4};
Table[0x25] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::ZP0, 3};
Table[0x35] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::ZPX, 4};
Table[0x45] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::ZP0, 3};
Table[0x55] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::ZPX, 4};
Table[0x65] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::ZP0, 3};
Table[0x75] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::ZPX, 4};
Table[0x85] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::ZP0, 3};
Table[0x95] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::ZPX, 4};
Table[0xA5] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::ZP0, 3};
Table[0xB5] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::ZPX, 4};
Table[0xC5] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::ZP0, 3};
Table[0xD5] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::ZPX, 4};
Table[0xE5] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ZP0, 3};
Table[0xF5] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ZPX, 4};
Table[0x06] = INSTRUCTION {"ASL", &Cpu::ASL, &Cpu::ZP0, 5};
Table[0x16] = INSTRUCTION {"ASL", &Cpu::ASL, &Cpu::ZPX, 6};
Table[0x26] = INSTRUCTION {"ROL", &Cpu::ROL, &Cpu::ZP0, 5};
Table[0x36] = INSTRUCTION {"ROL", &Cpu::ROL, &Cpu::ZPX, 6};
Table[0x46] = INSTRUCTION {"LSR", &Cpu::LSR, &Cpu::ZP0, 5};
Table[0x56] = INSTRUCTION {"LSR", &Cpu::LSR, &Cpu::ZPX, 6};
Table[0x66] = INSTRUCTION {"ROR", &Cpu::ROR, &Cpu::ZP0, 5};
Table[0x76] = INSTRUCTION {"ROR", &Cpu::ROR, &Cpu::ZPX, 6};
Table[0x86] = INSTRUCTION {"STX", &Cpu::STX, &Cpu::ZP0, 3};
Table[0x96] = INSTRUCTION {"STX", &Cpu::STX, &Cpu::ZPY, 4};
Table[0xA6] = INSTRUCTION {"LDX", &Cpu::LDX, &Cpu::ZP0, 3};
Table[0xB6] = INSTRUCTION {"LDX", &Cpu::LDX, &Cpu::ZPY, 4};
Table[0xC6] = INSTRUCTION {"DEC", &Cpu::DEC, &Cpu::ZP0, 5};
Table[0xD6] = INSTRUCTION {"DEC", &Cpu::DEC, &Cpu::ZPX, 6};
Table[0xE6] = INSTRUCTION {"INC", &Cpu::INC, &Cpu::ZP0, 5};
Table[0xF6] = INSTRUCTION {"INC", &Cpu::INC, &Cpu::ZPX, 6};
Table[0x08] = INSTRUCTION {"PHP", &Cpu::PHP, &Cpu::IMP, 3};
Table[0x18] = INSTRUCTION {"CLC", &Cpu::CLC, &Cpu::IMP, 2};
Table[0x28] = INSTRUCTION {"PLP", &Cpu::PLP, &Cpu::IMP, 4};
Table[0x38] = INSTRUCTION {"SEC", &Cpu::SEC, &Cpu::IMP, 2};
Table[0x48] = INSTRUCTION {"PHA", &Cpu::PHA, &Cpu::IMP, 3};
Table[0x58] = INSTRUCTION {"CLI", &Cpu::CLI, &Cpu::IMP, 2};
Table[0x68] = INSTRUCTION {"PLA", &Cpu::PLA, &Cpu::IMP, 4};
Table[0x78] = INSTRUCTION {"SEI", &Cpu::SEI, &Cpu::IMP, 2};
Table[0x88] = INSTRUCTION {"DEY", &Cpu::DEY, &Cpu::IMP, 2};
Table[0x98] = INSTRUCTION {"TYA", &Cpu::TYA, &Cpu::IMP, 2};
Table[0xA8] = INSTRUCTION {"TAY", &Cpu::TAY, &Cpu::IMP, 2};
Table[0xB8] = INSTRUCTION {"CLV", &Cpu::CLV, &Cpu::IMP, 2};
Table[0xC8] = INSTRUCTION {"INY", &Cpu::INY, &Cpu::IMP, 2};
Table[0xD8] = INSTRUCTION {"CLD", &Cpu::CLD, &Cpu::IMP, 2};
Table[0xE8] = INSTRUCTION {"INX", &Cpu::INX, &Cpu::IMP, 2};
Table[0xF8] = INSTRUCTION {"SED", &Cpu::SED, &Cpu::IMP, 2};
Table[0x09] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::IMM, 2};
Table[0x19] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::ABY, 4};
Table[0x29] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::IMM, 2};
Table[0x39] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::ABY, 4};
Table[0x49] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::IMM, 2};
Table[0x59] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::ABY, 4};
Table[0x69] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::IMM, 2};
Table[0x79] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::ABY, 4};
Table[0x99] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::ABY, 5};
Table[0xA9] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::IMM, 2};
Table[0xB9] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::ABY, 4};
Table[0xC9] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::IMM, 2};
Table[0xD9] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::ABY, 4};
Table[0xE9] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::IMM, 2};
Table[0xF9] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ABY, 4};
Table[0x0A] = INSTRUCTION {"ASL", &Cpu::ASL, &Cpu::IMP, 2};
Table[0x2A] = INSTRUCTION {"ROL", &Cpu::ROL, &Cpu::IMP, 2};
Table[0x4A] = INSTRUCTION {"LSR", &Cpu::LSR, &Cpu::IMP, 2};
Table[0x6A] = INSTRUCTION {"ROR", &Cpu::ROR, &Cpu::IMP, 2};
Table[0x8A] = INSTRUCTION {"TXA", &Cpu::TXA, &Cpu::IMP, 2};
Table[0x9A] = INSTRUCTION {"TXS", &Cpu::TXS, &Cpu::IMP, 2};
Table[0xAA] = INSTRUCTION {"TAX", &Cpu::TAX, &Cpu::IMP, 2};
Table[0xBA] = INSTRUCTION {"TSX", &Cpu::TSX, &Cpu::IMP, 2};
Table[0xCA] = INSTRUCTION {"DEX", &Cpu::DEX, &Cpu::IMP, 2};
Table[0xEA] = INSTRUCTION {"NOP", &Cpu::NOP, &Cpu::IMP, 2};
Table[0x2C] = INSTRUCTION {"BIT", &Cpu::BIT, &Cpu::ABS, 4};
Table[0x4C] = INSTRUCTION {"JMP", &Cpu::JMP, &Cpu::ABS, 3};
Table[0x6C] = INSTRUCTION {"JMP", &Cpu::JMP, &Cpu::IND, 5};
Table[0x8C] = INSTRUCTION {"STY", &Cpu::STY, &Cpu::ABS, 4};
Table[0xAC] = INSTRUCTION {"LDY", &Cpu::LDY, &Cpu::ABS, 4};
Table[0xBC] = INSTRUCTION {"LDY", &Cpu::LDY, &Cpu::ABX, 4};
Table[0xCC] = INSTRUCTION {"CPY", &Cpu::CPY, &Cpu::ABS, 4};
Table[0xEC] = INSTRUCTION {"CPX", &Cpu::CPX, &Cpu::ABS, 4};
Table[0x0D] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::ABS, 4};
Table[0x1D] = INSTRUCTION {"ORA", &Cpu::ORA, &Cpu::ABX, 4};
Table[0x2D] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::ABS, 4};
Table[0x3D] = INSTRUCTION {"AND", &Cpu::AND, &Cpu::ABX, 4};
Table[0x4D] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::ABS, 4};
Table[0x5D] = INSTRUCTION {"EOR", &Cpu::EOR, &Cpu::ABX, 4};
Table[0x6D] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::ABS, 4};
Table[0x7D] = INSTRUCTION {"ADC", &Cpu::ADC, &Cpu::ABX, 4};
Table[0x8D] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::ABS, 4};
Table[0x9D] = INSTRUCTION {"STA", &Cpu::STA, &Cpu::ABX, 5};
Table[0xAD] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::ABS, 4};
Table[0xBD] = INSTRUCTION {"LDA", &Cpu::LDA, &Cpu::ABX, 4};
Table[0xCD] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::ABS, 4};
Table[0xDD] = INSTRUCTION {"CMP", &Cpu::CMP, &Cpu::ABX, 4};
Table[0xED] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ABS, 4};
Table[0xFD] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ABX, 4};
Table[0x0E] = INSTRUCTION {"ASL", &Cpu::ASL, &Cpu::ABS, 6};
Table[0x1E] = INSTRUCTION {"ASL", &Cpu::ASL, &Cpu::ABX, 7};
Table[0x2E] = INSTRUCTION {"ROL", &Cpu::ROL, &Cpu::ABS, 6};
Table[0x3E] = INSTRUCTION {"ROL", &Cpu::ROL, &Cpu::ABX, 7};
Table[0x4E] = INSTRUCTION {"LSR", &Cpu::LSR, &Cpu::ABS, 6};
Table[0x5E] = INSTRUCTION {"LSR", &Cpu::LSR, &Cpu::ABX, 7};
Table[0x6E] = INSTRUCTION {"ROR", &Cpu::ROR, &Cpu::ABS, 6};
Table[0x7E] = INSTRUCTION {"ROR", &Cpu::ROR, &Cpu::ABX, 7};
Table[0x8E] = INSTRUCTION {"STX", &Cpu::STX, &Cpu::ABS, 4};
Table[0x9E] = INSTRUCTION {"LDX", &Cpu::LDX, &Cpu::ABS, 4};
Table[0xAE] = INSTRUCTION {"LDX", &Cpu::LDX, &Cpu::ABY, 4};
Table[0xBE] = INSTRUCTION {"DEC", &Cpu::DEC, &Cpu::ABS, 6};
Table[0xCE] = INSTRUCTION {"DEC", &Cpu::DEC, &Cpu::ABX, 7};
Table[0xDE] = INSTRUCTION {"INC", &Cpu::INC, &Cpu::ABS, 6};
Table[0xEE] = INSTRUCTION {"INC", &Cpu::INC, &Cpu::ABX, 7};
*/


}

Cpu::~Cpu(){}; //Distructor



void Cpu::Reset(u16 start_addr)
{
m_cycles = 0;
m_skipCycles = 0;
m_ac = 0;     
m_regX = 0;     
m_regY = 0;   
m_st_reg = 0 ;   
m_pc = start_addr;      
m_sp = 0xfd;     

}


void Cpu::Interrupt(){}

void Cpu::Execute_Cycle(){}

void Cpu::Push_Stack(u8 value)

{

Push_Stack(value >> 8);
Push_Stack(value & 0x00FF);

}

u8 Cpu::IMP(){}

u8 Cpu::IMM(){}

u8 Cpu::ZP0(){}

u8 Cpu::ZPX(){}

u8 Cpu::ZPY(){}

u8 Cpu::ABS(){}

u8 Cpu::ABX(){}

u8 Cpu::ABY(){}

u8 Cpu::REL(){}

u8 Cpu::IND(){}

u8 Cpu::IZX(){}

u8 Cpu::IZY(){}

/*
BRK initiates a software interrupt similar to a hardware
interrupt (IRQ). The return address pushed to the stack is
PC+2, providing an extra byte of spacing for a break mark
(identifying a reason for the break.)
The status register will be pushed to the stack with the break
flag set to 1. However, when retrieved during RTI or by a PLP
instruction, the break flag will be ignored.
The interrupt disable flag is not set automatically.
*/

u8 Cpu::BRK()
{
    
m_pc++;
Push_Stack(u8( m_pc >> 8));
Push_Stack((u8) m_pc);
Push_Stack(m_status | B );

}
// branch on N = 0

u8 Cpu::BPL()
{
    
  //opbranch();
  
  if (N == 0)
{
 
  (m_pc,m_pc +  m_addr);
      
      m_pc + m_addr ;

}


}
// Jump to New Location Saving Return Address
u8 Cpu::JSR(){

m_pcm = m_pc -1;
Push_Stack(u8( m_pc >> 8));
Push_Stack((u8) m_pcm);
m_pc = m_addr;


}


//branch on N = 1
u8 Cpu::BMI()
{

  //opbranch();

  if (N == 1)
{
 
  (m_pc,m_pc +  m_addr);
      
      m_pc + m_addr ;

}


}



/*               RTI
    Return from Interrupt
    The status register is pulled with the break flag
    and bit 5 ignored. Then PC is pulled from the stack.
*/
u8 Cpu::RTI(){}

u8 Cpu::BVC(){}

u8 Cpu::RTS(){}

u8 Cpu::BVS(){}

u8 Cpu::BCC(){}

u8 Cpu::LDY(){}

u8 Cpu::BCS(){}

u8 Cpu::CPY(){}

u8 Cpu::BNE(){}

u8 Cpu::CPX(){}

u8 Cpu::BEQ(){}

u8 Cpu::AND(){}

u8 Cpu::ORA(){}

u8 Cpu::EOR(){}

u8 Cpu::ADC(){}

u8 Cpu::STA(){}

u8 Cpu::LDA(){}

u8 Cpu::CMP(){}

u8 Cpu::SBC(){}

u8 Cpu::LDX(){}

u8 Cpu::BIT(){}

u8 Cpu::STY(){}

u8 Cpu::ASL(){} 

u8 Cpu::ROL(){}

u8 Cpu::LSR(){}

u8 Cpu::ROR(){}

u8 Cpu::STX(){}

u8 Cpu::DEC(){}

u8 Cpu::INC(){}

u8 Cpu::PHP(){}

u8 Cpu::CLC(){}

u8 Cpu::PLP(){}

u8 Cpu::SEC(){}

u8 Cpu::PHA(){}

u8 Cpu::CLI(){}

u8 Cpu::PLA(){}

u8 Cpu::SEI(){}

u8 Cpu::DEY(){}

u8 Cpu::TYA(){} 

u8 Cpu::TAY(){}

u8 Cpu::CLV(){}

u8 Cpu::INY(){}

u8 Cpu::CLD(){}

u8 Cpu::INX(){}

u8 Cpu::SED(){}

u8 Cpu::TXA(){}

u8 Cpu::TXS(){}

u8 Cpu::TAX(){}

u8 Cpu::TSX(){}  

u8 Cpu::DEX(){}

u8 Cpu::NOP(){} 

u8 Cpu::JMP(){}


    

 
  	

        
      









}

