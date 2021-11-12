#include"Typedef.h"


namespace olc6502

{

const auto ResetVector = 0xfffc;
u16 readAddress(u16 addr);

class Cpu

{


private:



public:
  Cpu();
  ~Cpu ();


   u8 (Cpu::*CodeExec)(void);
   u8 (Cpu::*AddrExec)(void);


     struct INSTRUCTION
     {
         std::string name;
         u8     (Cpu::*operate )(void) = nullptr;
         u8     (Cpu::*addrmode)(void) = nullptr;
         u8      cycles = 0;
     };
    
     std::vector<INSTRUCTION> Table;





//opcode
u8 ADC();  u8 AND();  u8 ASL();   u8 BCC(); 	
u8 BCS();  u8 BEQ();  u8 BIT();   u8 BMI(); 	
u8 BNE();  u8 BPL();  u8 BRK();   u8 BVC(); 	
u8 BVS();  u8 CLC();  u8 CLD();   u8 CLI();
u8 CLV();  u8 CMP();  u8 CPX();   u8 CPY();
u8 DEC();  u8 DEX();  u8 DEY();   u8 EOR();
u8 INC();  u8 INX();  u8 INY();   u8 JMP();
u8 JSR();  u8 LDA();  u8 LDX();   u8 LDY();
u8 LSR();  u8 NOP();  u8 ORA();   u8 PHA();
u8 PHP();  u8 PLA();  u8 PLP();   u8 ROL(); 	
u8 RTS();  u8 SBC();  u8 SEC();   u8 SED();
u8 SEI();  u8 STA();  u8 STX();   u8 STY();
u8 TAX();  u8 TAY();  u8 TSX();   u8 TXA();
u8 TXS();  u8 TYA();  u8 ROR();   u8 RTI();


//Addr
u8 IMP();
u8 IMM();
u8 ZP0();
u8 ZPX();
u8 ZPY();
u8 ABS();
u8 ABX();
u8 ABY();
u8 REL();
u8 IND();
u8 IZX();
u8 IZY();





void Init();
void Execute_Cycle();
void Reset();
void Reset(u16 start_addr);
bool Load(const char **);
void Nmi();
void Irq();
void Fetch();
void Interrupt();
void opbranch();
void Push_Stack(u8);
void Pop();


 // CPU registers             
u8 m_ac ;           //Accumulator
u8 m_regX;         // Register_X
u8 m_regY;         // Register_Y
u8 m_pc;          //Program_Counter
u8 m_sp;           //Stack_Pointer
u8 m_st_reg;      //Status_Register
u8 m_skipCycles;
u8 m_cycles;
u8 m_status;
u16 m_addr;
u8 m_pcm;

enum  FLAGS {


  C = ( 1 << 0 ),           // CARRY
  Z = ( 1 << 1 ),          // ZERO 
  I = ( 1 << 2 ),         // Interrupt Disable
  D = ( 1 << 3 ),        // DECIMAL  
  B = ( 1 << 5 ),       // BREAK
  N = ( 1 << 6 ),     // Negative
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


