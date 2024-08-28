#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "tag.h"

class Controller
{
public:
    Controller(){}

    void openFile(string filePathName);
    string getUID();
    string getBCC();
    bool checkBCC();
    string getManufacturerData();
    std::vector<Sector> getTagData();
    Sector getSector(unsigned short sectorNumber);
    string getPasswordA(unsigned short sectorNumber);
    string getPasswordB(unsigned short sectorNumber);
    string getAccessBits(unsigned short sectorNumber);

private:
    Tag tag;
    void setTag(Tag tag);
};

#endif // CONTROLLER_H
