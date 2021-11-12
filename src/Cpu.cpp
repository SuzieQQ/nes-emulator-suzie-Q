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

