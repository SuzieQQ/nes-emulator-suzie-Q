#include"Bus.h"
#include"Cpu.h"

namespace olc6502
{
Bus::Bus()
{
 
cpu.ConnectBus(this);

for(auto &i : m_ram) i = 0x00;

}


Bus::~Bus(){}

void Bus::Write(u16 addr, u8 data)
{
    if (addr >= 0x0000 && addr <= 0xFFFF)
    
        m_ram[addr] = data;
    
    
}

u8 Bus::m_read(u16 addr, bool bReadonly)
{
   if (addr >= 0x0000 && addr <= 0xFFFF)
    
       return m_ram[addr];

        return 0x00;
    
}






}