#include"Typedef.h"
#include"Bus.h"
#include "Cpu.h"

namespace olc6502

{

u8 Cpu::m_read(u16 a )
{
return bus->m_read(a,false);
}  


void Cpu::Write(u16 a, u8 data)
{

bus->Write(a,data);

}


u8 Cpu::GetFlag(FLAGS f)
{
	return ((m_status & f) > 0) ? 1 : 0;
}

void Cpu::SetFlag(FLAGS f, bool v)
{
    if (v)
		m_status |= f;
	else
		m_status &= ~f;
}


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

}

Cpu::~Cpu(){}; //Distructor



void Cpu::Reset(u16 m_start_addr)
{
m_cycles = 0;
m_skipCycles = 0;
m_ac = 0;     
m_regX = 0;     
m_regY = 0;   
m_st_reg = 0 ;   
m_pc = m_start_addr;      
m_sp = 0xfd;     

}


void Cpu::Interrupt()
{

}

void Cpu::Execute_Cycle()
{

}


u8 Cpu::fetch()
{
  if (!(Table[m_opcode].addrmode == &Cpu::IMP))
		m_fetched = m_read(m_addr_a);
	return m_fetched;
  
}

void Cpu::Push_Stack(u8 value)

{

Push_Stack(value >> 8);
Push_Stack(value & 0x00FF);

}

u8 Cpu::IMP()
{
  m_fetched = m_ac;
}

u8 Cpu::IMM()
{
  m_addr_a = m_pc++;
}


u8 Cpu::ZP0()
{
  m_addr_a = m_read(m_pc);
  m_pc++;
  m_addr_a &= 0x00FF;
}

u8 Cpu::ZPX()
{
  m_addr_a = (m_read(m_pc) + m_regX); 
  m_pc++;
  m_addr_a &= 0x0FF;
}

u8 Cpu::ZPY()
{
  m_addr_a = (m_read(m_pc) + m_regY); 
  m_pc++;
  m_addr_a &= 0x0FF;
}

u8 Cpu::ABS()
{
  u8 lo = m_read(m_pc);
  m_pc++;
  u8 hi = m_read(m_pc);
  m_pc++;
  m_addr_a = ( hi << 8) | lo ;
}

u8 Cpu::ABX()
{
  u8 lo = m_read(m_pc);
  m_pc++;
  u8 hi = m_read(m_pc);
  m_pc++;
  m_addr_a = ( hi << 8) | lo ;
  m_addr_a += m_regX;

  if ((m_addr_a & 0xFF00) != (hi << 8))
  return 1;
  else 
  return 0;
  

}

u8 Cpu::ABY()
{
  u8 lo = m_read(m_pc);
  m_pc++;
  u8 hi = m_read(m_pc);
  m_pc++;
  m_addr_a = ( hi << 8) | lo ;
  m_addr_a += m_regY;

  if ((m_addr_a & 0xFF00) != (hi << 8))
  return 1;
  else 
  return 0;
}

u8 Cpu::REL()
{

if ((m_start & 0xff00) == (m_end & 0xff0))
m_cycles++;
else
m_cycles +=2;

}

u8 Cpu::IND()
{
  u8 lo = m_read(m_pc);
	m_pc++;
	u8 hi = m_read(m_pc);
	m_pc++;

	u8 ptr = (hi << 8) | lo;

	if (lo == 0x00FF)
	m_addr_a= (m_read(ptr & 0xFF00) << 8) | m_read(ptr + 0);
	else 
	m_addr_a = (m_read(ptr + 1) << 8) | m_read(ptr + 0);
	
	return 0;
  
}

u8 Cpu::IZX()
{
  u8 t = m_read(m_pc);
	m_pc++;

	u8 lo = m_read((u16)(t + (u16)m_regX) & 0x00FF);
	u8 hi = m_read((u16)(t + (u16)m_regX + 1) & 0x00FF);

	m_addr_a = (hi << 8) | lo;
	
	return 0;
}

u8 Cpu::IZY()
{
  u8 t= m_read(m_pc);
  m_pc++;
  u8 lo = m_read(t & 0x00FF);
  u8 hi = m_read((t+ 1) & 0x00FF);
  m_addr_a = ( hi << 8) | lo;
  m_addr_a += m_regY;

  if ((m_addr_a & 0xFF00) !=(hi << 8))
  return (1);
  else
  return (0);
}

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
    
  
  if (GetFlag(N) == 0)
{
 
  (m_pc,m_pc +  m_addr_a);
      
      m_pc + m_addr_a ;

}


}
// Jump to New Location Saving Return Address
u8 Cpu::JSR(){

m_pc --;
Push_Stack(u8( m_pc >> 8));
Push_Stack((u8) m_pc);
m_pc = m_addr_a;


}


//branch on N = 1
u8 Cpu::BMI()
{

  //opbranch();

  if (GetFlag(N) == 1)
{
 
  (m_pc,m_pc +  m_addr_a);
      
      m_pc + m_addr_a ;

}


}


/*               RTI
    Return from Interrupt
    The status register is pulled with the break flag
    and bit 5 ignored. Then PC is pulled from the stack.
*/
u8 Cpu::RTI()
{
m_sp++;
	m_status = m_read(0x0100 + m_sp);
	m_status &= ~B;
	m_status &= ~B;

	m_sp++;
	m_pc =  (u16)m_read(0x0100 + m_sp);
	m_sp++;
	m_pc |= (u16)m_read(0x0100 + m_sp) << 8;
	

}


   

//Branch on Overflow Clear   branch on V = 0
u8 Cpu::BVC()
{
 if (GetFlag(V) == 0)
 {
   m_cycles++;
   m_addr_a = m_pc + m_addr_b;

    if ((m_addr_a & 0xFF00) != (m_pc & 0xFF00))
			m_cycles++;

		m_pc = m_addr_a;
 }
 
}


/*
Return from Subroutine
pull PC, PC+1 -> PC
*/
u8 Cpu::RTS()
{
  m_sp++;
  m_pc = (u8)m_read(0x0100 + m_sp);
  m_sp++;
  m_pc |= (u8)m_read(0x0100 + m_sp) << 8;
  m_pc++;

}

//branch on V = 1
u8 Cpu::BVS()
{
if (GetFlag(V)==1)
m_cycles++;

}

//branch on C = 0 Branch on Carry Clear
u8 Cpu::BCC()
{
if (GetFlag(C)==0)
m_cycles++;
SetFlag(C, false);
}

// Load index Y with memory
u8 Cpu::LDY() 
{
  fetch();
  m_regY = m_fetched;
  SetFlag(Z, m_regY == 0x00);
  SetFlag(N, m_regY & 0x80);
}

//Branch on Carry Set
u8 Cpu::BCS()
{
  if (GetFlag(C)==1)
  {
    m_cycles++;
    m_addr_a = m_pc + m_addr_b;
    if ((m_addr_a & 0xFF00 ) != (m_pc & 0xFF00 ))
    m_cycles++;

    m_pc = m_addr_a;
    
    
  }
  
}

//Compare Memory and Index Y
u8 Cpu::CPY()
{
  fetch();
  SetFlag(N,m_temp & 0x0080 );
  SetFlag(Z,(m_temp & 0x00FF) == 0x0000);
  SetFlag(C,m_regY >= m_fetched );

}

//Branch on Result not Zero
u8 Cpu::BNE()
{
  if (GetFlag(Z) == 0)
	{
		m_cycles++;
		m_addr_a = m_pc + m_addr_b;

		if ((m_addr_a & 0xFF00) != (m_pc & 0xFF00))
			m_cycles++;

		m_pc = m_addr_a;
	}
	return (0);
}

u8 Cpu::CPX(){}

//Branch on Result Zero
u8 Cpu::BEQ()
{
   if (GetFlag(Z) == 1)
	{
		m_cycles++;
		m_addr_a = m_pc + m_addr_b;

		if ((m_addr_a & 0xFF00) != (m_pc & 0xFF00))
			m_cycles++;

		m_pc = m_addr_a;
	}
	return (0);

}

// AND Memory with Accumulator
u8 Cpu::AND()
{
  fetch();
	m_ac = m_ac & m_fetched;
	SetFlag(Z, m_ac == 0x00);
	SetFlag(N, m_ac & 0x80);
	return (1);
}

u8 Cpu::ORA()
{
  fetch();
	m_ac = m_ac | m_fetched;
	SetFlag(Z, m_ac == 0x00);
	SetFlag(N, m_ac & 0x80);
	return (1);
}

u8 Cpu::EOR(){}

//Add Memory to Accumulator with Carry
u8 Cpu::ADC()
{
  fetch();
  m_temp = (u16)m_ac + (u16)m_fetched + (u16)GetFlag(C);
  SetFlag(V,(~((u16)m_ac ^ (u16)m_fetched) & ((u16)m_ac ^ (u16)m_temp)) & 0x0080);
  SetFlag(C,m_temp > 255);
  SetFlag(Z,(m_temp & 0x00FF) == 0);
  SetFlag(N, m_temp & 0x80);

}

// "Store Accumulator in Memory";
u8 Cpu::STA()
{
  Write(m_addr_a, m_ac);
  return(0);
}

u8 Cpu::LDA(){}

u8 Cpu::CMP(){}

//Subtract Memory from Accumulator with Borrow
u8 Cpu::SBC()
{
  u16 m_value = ((u16)m_fetched) ^ 0x00FF;
  m_temp = (u16)m_ac + m_value + (u16)GetFlag(C);
  SetFlag(N, m_temp & 0x0080);
  SetFlag(Z, ((m_temp & 0x00FF) == 0));
  SetFlag(C, m_temp & 0x00FF00);
  SetFlag(V, (m_temp ^ (u16)m_ac)& (m_temp ^ m_value) & 0x0080);
  m_ac = m_temp & 0x00FF;
  return(1);
}

u8 Cpu::LDX(){}

u8 Cpu::BIT(){}
// "Store Index Y in Memory";
u8 Cpu::STY()
{
  Write(m_addr_a, m_regY);
  return(0);
}

u8 Cpu::ASL(){} 

// "Rotate One Bit Left (Memory or Accumulator";
u8 Cpu::ROL()
{
  fetch();
	m_temp = (u16)(m_fetched << 1) | GetFlag(C);
	SetFlag(C, m_temp & 0xFF00);
	SetFlag(Z, (m_temp & 0x00FF) == 0x0000);
	SetFlag(N, m_temp & 0x0080);
	if (Table[m_opcode].addrmode == &Cpu::IMP)
	m_ac = m_temp & 0x00FF;
	else
	Write(m_addr_a, m_temp & 0x00FF);
	return (0);
}

u8 Cpu::LSR()
{
  fetch();
  SetFlag(C, m_fetched & 0x0001);
  m_temp = m_fetched >> 1;
  SetFlag(Z, (m_temp & 0x00FF) == 0x0000);
  SetFlag(N, m_temp & 0x0080);
  if (Table[m_opcode].addrmode == &Cpu::IMP)
  m_ac = m_temp & 0x00FF;
  else
  Write(m_addr_a, m_temp & 0x00FF);
  
}
//Rotate One Bit Right (Memory or Accumulator)
u8 Cpu::ROR()
{
  fetch();
	m_temp = (u16)(GetFlag(C) << 7) | (m_fetched >> 1);
	SetFlag(C, m_fetched & 0x01);
	SetFlag(Z, (m_temp & 0x00FF) == 0x00);
	SetFlag(N, m_temp & 0x0080);
	if (Table[m_opcode].addrmode == &Cpu::IMP)
	m_ac = m_temp & 0x00FF;
	else
	Write(m_addr_a, m_temp & 0x00FF);
	return (0);

}
// "Store Index X in Memory";
u8 Cpu::STX()
{
  Write(m_addr_a, m_regX);
  return(0);
}

u8 Cpu::DEC(){}

u8 Cpu::INC(){}

//Push Processor Status on Stack
u8 Cpu::PHP()
{
  Write(0x0100 + m_sp, m_status | B | U);
  SetFlag(B,0);
  SetFlag(U,0);
  m_sp--;
  return (0);
}

u8 Cpu::CLC(){}

u8 Cpu::PLP()
{
  m_sp++;
  m_status =m_read(0x0100 + m_sp);
  SetFlag(U,true);
  return(0);
}

//Set Carry Flag
u8 Cpu::SEC()
{
  SetFlag(C,1);
  return(0);
}

//Push Accumulator on Stack
u8 Cpu::PHA()
{
 Write(0x0100 + m_sp, m_ac);
 m_sp--;
 return 0; 
}

u8 Cpu::CLI(){}

u8 Cpu::PLA()
{
  m_sp++;
  m_ac = m_read(0x0100 + m_sp);
  SetFlag(Z, m_ac == 0x00);
  SetFlag(N, m_ac & 0x80);
  return(0);
}

//Set Interrupt Disable Status
u8 Cpu::SEI()
{
  SetFlag(I,1);
  return(0);
}

u8 Cpu::DEY(){}

u8 Cpu::TYA(){} 
//Transfer Accumulator to Index Y
u8 Cpu::TAY()
{
 m_regY = m_ac;
 SetFlag(Z,m_ac == 0x00);
 SetFlag(N,m_ac & 0x80);
 return(0);

}

u8 Cpu::CLV(){}

// "Increment Index Y by One";
u8 Cpu::INY()
{
  SetFlag(N,m_regY & 0x80);
  SetFlag(Z,m_regY == 0x00);
  m_regY++;
  return(0);

}

u8 Cpu::CLD(){}

// "Increment Index X by One";
u8 Cpu::INX()
{
  SetFlag(N,m_regX & 0x80);
  SetFlag(Z,m_regX == 0x00);
  m_regX++;
  return(0);
}

//Set Decimal Flag
u8 Cpu::SED()
{
  SetFlag(D,1);
  return(0);
}

//Transfer Index X to Accumulator
u8 Cpu::TXA()
{
 m_ac = m_regX;
 SetFlag(Z,m_ac == 0x00);
 SetFlag(N,m_ac & 0x80);
return(0);
}

// "Transfer Index X to Stack Register";
u8 Cpu::TXS()
{
  m_sp = m_regX;
  return(0);
}

// "Transfer Accumulator to Index X";
u8 Cpu::TAX()
{
 
 m_regX = m_ac;
 SetFlag(Z,m_ac == 0x00);
 SetFlag(N,m_ac & 0x80);
 return(0);

}
//Transfer Stack Pointer to Index X
u8 Cpu::TSX()
{

m_sp = m_regX;
SetFlag(N, m_ac & 0x80);
SetFlag(Z, m_ac == 0x00);
return(0);
}  

u8 Cpu::DEX(){}

u8 Cpu::NOP()
{
  switch (m_opcode) {
	case 0x1C:
	case 0x3C:
	case 0x5C:
	case 0x7C:
	case 0xDC:
	case 0xFC:
		return 1;
		break;
	}
	return 0;
} 

u8 Cpu::JMP(){}


    

 
  	

        
      









}

