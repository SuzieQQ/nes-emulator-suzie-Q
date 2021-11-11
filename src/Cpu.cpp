#include"Typedef.h"
#include "Cpu.h"

namespace olc6502

{

Cpu::Cpu() //Costructor
{

for (int i = 0; i < 256; i++)

Table[0x00] = INSTRUCTION {"BRK", &Cpu::BRK, &Cpu::IMP, 7};
Table[0x10] = INSTRUCTION {"BPL", &Cpu::BPL, &Cpu::REL, 2};
//Table[0x20] = INSTRUCTION {"JSR", &Cpu::JSR, &Cpu::ABS, 6};
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

u8 Cpu::BRK()
{
    
m_pc++;
Push_Stack(u8( m_pc >> 8));
Push_Stack((u8) m_pc);
Push_Stack(m_status | B );

}

u8 Cpu::BPL(){}

u8 Cpu::JSR(){}




}

