#include<iostream>
#include "cartridge.h"
#include "typedef.h"



namespace CartidgeNES
{

Cartridge::Cartridge() :
m_mapperNumber(0),
m_extended_RAM(false),
m_nametablemirroring(0)
{

}

const std::vector<u8>& Cartridge::get_Rom()
{
    return m_PRG_ROM;
}

const std::vector<u8>& Cartridge::get_VRom()
{

return m_CHR_ROM;

}

u8 Cartridge::get_mapper()
{

    return m_mapperNumber;
}

u8 Cartridge::get_nametablemirroring()

{
return m_nametablemirroring;

}

bool Cartridge::RAM_extended()
{

return m_extended_RAM;

}




bool Cartridge::load_file(std::string path)
{

std::ifstream romFile (path, std::ios_base::binary | std::ios_base::in );

if (!romFile)

{
   std::cout << "Could not open ROM file from path: " << path << std::endl;
            return false;

}

std::vector<u8> header;
header.resize(0x10);
if (!romFile.read(reinterpret_cast<char*>(&header[0]), 0x10))
{
    std::cout<<" Reading iNES header failed " <<std::endl;
    return false;
}
if (std::string{&header[0], &header[4]} != "NES\x1A")
{
    std::cout<<" Not a valid iNES image. Magic Number: "
    << std::hex << header[0] << " "
    << header[1] << " " << header[2] << " " << int(header[3]) << std::endl
    << "Valid magic number : N E S 1a" << std::endl;
            return false;
}


 u8 banks = header[4];
        std::cout << "16KB PRG-ROM Banks: " << +banks << std::endl;
        if (!banks)
        {
            std::cout << "ROM has no PRG-ROM banks. Loading ROM failed." << std::endl;
            return false;
        }






u8 wbanks = header[5];
        std::cout << "8KB CHR-ROM Banks: " << +wbanks << std::endl;

        m_nametablemirroring = header[6] & 0xB;
        std::cout << "Name Table Mirroring: " << +m_nametablemirroring << std::endl;

        m_mapperNumber = ((header[6] >> 4) & 0xf) | (header[7] & 0xf0);
        std::cout << "Mapper #: " << +m_mapperNumber << std::endl;

        m_extended_RAM = header[6] & 0x2;
        std::cout << "Extended (CPU) RAM: " << std::boolalpha << m_extended_RAM << std::endl;

        if (header[6] & 0x4)
        {
            std::cout << "Trainer is not supported." << std::endl;
            return false;
        }

        if ((header[0xA] & 0x3) == 0x2 || (header[0xA] & 0x1))
        {
            std::cout << "PAL ROM not supported." << std::endl;
            return false;
        }
        else
            std::cout << "ROM is NTSC compatible.\n";

        m_PRG_ROM.resize(0x4000 * banks);
        if (!romFile.read(reinterpret_cast<char*>(&m_PRG_ROM[0]), 0x4000 * banks))
        {
            std::cout << "Reading PRG-ROM from image file failed." << std::endl;
            return false;
        }

        
        if (wbanks)
        {
            m_CHR_ROM.resize(0x2000 * wbanks);
            if (!romFile.read(reinterpret_cast<char*>(&m_CHR_ROM[0]), 0x2000 * wbanks))
            {
                std::cout << "Reading CHR-ROM from image file failed." << std::endl;
                return false;
            }
        }
        else
            std::cout << "Cartridge with CHR-RAM." << std::endl;
        return true;
    }
}






