
#include<vector>
#include<string.h>
#include "cpu.h"
#include<iomanip>
using namespace Olc6502;

Olc6502::Cpu::Cpu(){}; //Costructor
Olc6502::Cpu::~Cpu(){}; //Distructor





 
void Cpu::Reset(u16 start_addr)
{
m_cycles = 0;
m_skipCycles = 0;
AC = 0;     
REG_X = 0;     
REG_Y = 0;   
ST_REG = 0 ;   
PC = start_addr;      
SP = 0xfd;     

}


void Cpu::Interrupt()
{

}







void Cpu::Execute_Cycle()
{



}


