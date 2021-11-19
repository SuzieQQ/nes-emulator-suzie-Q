#pragma once
#include "Typedef.h"
#include "Cpu.h"

namespace olc6502
{


class Bus
{

public:
    Bus();
    ~Bus();

public:
Cpu cpu;

//Ram
std::array<u8 , 64 * 1024>  m_ram;

//Bus Read & Write
void Write(u16 addr, u8 data);
u8 m_read (u16 addr ,  bool bReadOnly = false);

};


}



