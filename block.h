#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <array>
#include <iostream>
#include "constants.h"
using namespace std;

class Block
{
public:
    Block(std::array<unsigned char, BLOCK_BYTES> data): data(data){}
    Block(): valid(false){}
    std::array<unsigned char, BLOCK_BYTES> getData();
    string toString();

private:
    std::array<unsigned char, BLOCK_BYTES> data;
    bool valid;

    string byteToStr();
};

#endif // BLOCK_H
