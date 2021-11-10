#include"Typedef.h"
#include "Cpu.h"



Cpu::Cpu()
{
 
Table =  {

{"BRK", &Cpu::BRK, &Cpu::IMM, 7},



};



} //Costructor

Cpu::~Cpu(){}; //Distructor



 
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



 u8 Cpu::IMP()
{
	
}


u8 Cpu::IMM()
{
	
}

u8 Cpu::BRK()
{

  
}