#include<iostream>
#include <vector>
#include <string>
#include <map>
#include<stdio.h>



typedef uint8_t u8;
typedef uint16_t u16;
typedef unsigned char uchar;




namespace Olc6502{

const auto ResetVector = 0xfffc;
u16 readAddress(u16 addr);

class Cpu
{
private:

 

public:
  Cpu();
  ~Cpu ();







//opcode
u8 ADC();  u8	AND(); 	u8 ASL(); 	u8 BCC(); 	u8 BCS(); 	u8 BEQ(); 	u8 BIT(); 	u8 BMI(); 	u8 BNE(); 	u8 BPL(); 	u8 BRK(); 	u8 BVC(); 	u8 BVS(); 	u8 CLC();
u8 CLD();  u8	CLI(); 	u8 CLV(); 	u8 CMP(); 	u8 CPX(); 	u8 CPY(); 	u8 DEC(); 	u8 DEX(); 	u8 DEY(); 	u8 EOR(); 	u8 INC(); 	u8 INX(); 	u8 INY(); 	u8 JMP();
u8 JSR();  u8	LDA(); 	u8 LDX(); 	u8 LDY(); 	u8 LSR(); 	u8 NOP(); 	u8 ORA(); 	u8 PHA(); 	u8 PHP(); 	u8 PLA(); 	u8 PLP(); 	u8 ROL(); 	u8 ROR(); 	u8 RTI();
u8 RTS();  u8	SBC();  u8 SEC(); 	u8 SED(); 	u8 SEI(); 	u8 STA(); 	u8 STX(); 	u8 STY(); 	u8 TAX(); 	u8 TAY(); 	u8 TSX(); 	u8 TXA(); 	u8 TXS(); 	u8 TYA();


void Init();
void Execute_Cycle();
void Reset();
void Reset(u16 start_addr);
bool Load(const char **);
void NMI();
void IRQ();
void Fetch();
void Interrupt();
void Table();


                        // CPU registers
u8 AC ;                //Accumulator
u8 REG_X;             // Register_X
u8 REG_Y;            // Register_Y
u8 PC;              //Program_Counter
u8 SP;             //Stack_Pointer
u8 ST_REG;        //Status_Register
u8 m_skipCycles; // skip_cycles
u8 m_cycles;    // cycles


          //Addr  
u8 IMPL;             // IMPLICT
u8 IMM;             // IMMEDIATE
u8 ZP;             // ZERO PAGE
u8 ZPX;           // ZERO PAGE X
u8 ZPY;          // ZERO PAGE Y
u8 ABS;         // ABSOLUTE
u8 ABX;        // ABSOLUTE X
u8 ABY;       // ABSOLUTE Y
u8 IND;      //INDIRECT
u8 INDX;    //INDIRECT X
u8 INDY;   //INDIRECT Y
u8 REL;    //RELATIVE




enum class FLAGS{


  C = ( 1 << 0 ),           // CARRY
  Z = ( 1 << 1 ),          // ZERO 
  I = ( 1 << 2 ),         // Interrupt Disable
  D = ( 1 << 3 ),        // DECIMAL  
  B = ( 1 << 5 ),       // BREAK
  N = ( 1 << 6 ),      // Negative
  V = ( 1 << 7 ),     // Overflow    

   };

u8   GetFlag(FLAGS f);
void SetFlag(FLAGS f, bool v);

enum IORegisters
    {
        PPUCTRL = 0x2000,
        PPUMASK,
        PPUSTATUS,
        OAMADDR,
        OAMDATA,
        PPUSCROL,
        PPUADDR,
        PPUDATA,
        OAMDMA = 0x4014,
        JOY1 = 0x4016,
        JOY2 = 0x4017,
    };






  };


}


