#include"typedef.h"

namespace cartridge{


class Cartridge
{

public:
    Cartridge();

bool load_file(std::string path);
u8 get_mapper();
u8 get_nametablemirroring();
bool RAM_extended();


std::vector<u8> m_PRG_ROM;
std::vector<u8> m_CHR_ROM;
u8 m_nametablemirroring;
u8 m_mapperNumber;
bool m_extended_RAM;
bool m_xhrRam;



};




}