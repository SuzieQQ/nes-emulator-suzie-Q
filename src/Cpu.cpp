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
Table[0xE9] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::IMM, 2sS};
Table[0xF9] = INSTRUCTION {"SBC", &Cpu::SBC, &Cpu::ABY, 4};
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

u8 Cpu::REL(){}

u8 Cpu::ABS(){}

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


}

