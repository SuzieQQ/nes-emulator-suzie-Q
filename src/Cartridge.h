#include"Typedef.h"


namespace CartidgeNES
{


class Cartridge
{

public:
    Cartridge();

bool load_file(std::string path);
const std::vector<u8>& get_Rom();
const std::vector<u8>& get_VRom();
u8 get_mapper();
u8 get_nametablemirroring();
bool RAM_extended();


std::vector<u8> m_PRG_ROM;
std::vector<u8> m_CHR_ROM;
u8 m_nametablemirroring;
u8 m_mapperNumber;
bool m_extended_RAM;
bool m_chrRam;



};




}