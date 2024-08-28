#ifndef TAG_H
#define TAG_H
#include "sector.h"
#include "constants.h"

class Tag
{
public:
    Tag(): data(), uid() {}
    Tag(std::vector<Sector> sectors): data(sectors){}

    void addSector(Sector sector);
    Sector& getSector(unsigned short id);
    std::vector<Sector> getData();
    std::vector<unsigned char> getUID();
    unsigned char getBCC();
    std::vector<unsigned char> getManufacturerData();

private:
    std::vector<Sector> data;
    std::array<unsigned char, UID_TAG_LENGTH> uid;

};

#endif // TAG_H
