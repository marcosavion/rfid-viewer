#ifndef SECTOR_H
#define SECTOR_H
#include "block.h"
#include <vector>

class Sector
{
public:
    Sector(unsigned short id, std::vector<Block> data) : id(id), data(data) {}
    Sector(unsigned short id) : id(id), data() {}

    void addBlock(Block newBlock);
    Block getBlock(unsigned short blockID);
    std::vector<Block> getBlocks();
    unsigned short getID();
    string getIDStr();
    std::vector<unsigned char> getPasswordA();
    std::vector<unsigned char> getPasswordB();
    std::vector<unsigned char> getAccessBits();
    bool isValid();

private:
    unsigned short id;
    std::vector<Block> data;
    bool valid;
};

#endif // SECTOR_H
