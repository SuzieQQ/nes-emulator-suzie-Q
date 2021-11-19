#include"Typedef.h"

// finire da implementare


namespace ppu{
class PPU
{
private:

public:
  

 	



struct PPU_CTRL     //   $2000 
{
u8 tb =   2;      //table
u8 incr = 1;     // VRAM address increment per CPU read/write of PPUDATA
u8 spr_tb1 = 1; // Sprite pattern table address for 8x8 sprites
u8 btb = 1;    //|Background pattern table address (0: $0000; 1: $1000)
u8 spr_size = 1;  //Sprite size (0: 8x8 pixels; 1: 8x16 pixels)
u8 slave_select = 1; //PPU master/slave select (0: read backdrop from EXT pins; 1: output color on EXT pins)
u8 nmi = 1; //Generate an NMI at the start of the vertical blanking interval (0: off; 1: on)
};

struct PPU_MASK //$2001 
{
    
u8 gray = 1;         //Greyscale (0: normal color, 1: produce a greyscale display)
u8 backleft =1;     // Show background in leftmost 8 pixels of screen, 0: Hide
u8 spr_left = 1;   //Show sprites in leftmost 8 pixels of screen, 0: Hide
u8 backgshow = 1; //Show background
u8 sprshow = 1;  //Show sprites
u8 red =1 ;     //(green on PAL/Dendy)
u8 green =1 ;  //(red on PAL/Dendy)
u8 blue = 1;  //Emphasize blue



};

struct PPU_STATUS //$2002 
{

u8 bus = 5; 
u8 spr_over = 1;        // Sprite overflow. The intent was for this flag to be set
u8 spr_hit  = 1;       // Sprite 0 Hit.  Set when a nonzero pixel of sprite 0 overlaps
u8 v_blank  = 1;      // Vertical blank has started (0: not in vblank; 1: in vblank).






}ppu_status;




struct OAM_ADDR
{
    




};



/*
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
*/


};

}