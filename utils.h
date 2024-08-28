#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "block.h"
#include "sector.h"
#include "tag.h"


class Utils{
public:
    static Tag openFile(std::string filename);
    static Sector createSector(unsigned short id);
    static Block createBlock(std::string line);
    static std::array<unsigned char,16> hexStringToByteArray(const std::string& hexStr);
    static string byteToStr(std::vector<unsigned char> data);
    static string byteToStr(unsigned char data);
    static bool checkBBC(std::vector<unsigned char> uid, unsigned char bbc);
};
#endif // UTILS_H
