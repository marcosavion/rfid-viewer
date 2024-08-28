#include "utils.h"
#include "block.h"
#include "sector.h"
#include "tag.h"
#include "constants.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <format>
#include <regex>

using namespace std;

/**
 * @brief This method opens a file and create a Tag with all data
 * @param filePathName
 * @return The created tag object
 */
Tag Utils::openFile(string filePathName){

    string line;

    ifstream file(filePathName);

    unsigned short currentSector = 0;

    std::vector<Sector> sectors;

    std::regex pattern("[0-9]+");
    std::smatch match;

    if(file.is_open()){
        while(getline(file,line)){
            if(line.rfind("+",0)==0 && std::regex_search(line,match,pattern)){
                unsigned short test = stoi(match.str());
                while(currentSector != test){
                    cout << endl << "Creating sector..." << to_string(currentSector) << endl;
                    sectors.push_back(Utils::createSector(currentSector));
                    currentSector++;
                }
                cout << endl << "Creating sector..." << match.str() << endl;
                sectors.push_back(Utils::createSector(currentSector));
                currentSector++;
            }else{
                cout << "Creating block...";
                sectors.back().addBlock(Utils::createBlock(line));

            }
        }
    }

    Tag tag(sectors);

    file.close();

    return tag;
}


/**
 * @brief Creates a Sector with the given id
 * @param id
 * @return Sector object
 */
Sector Utils::createSector(unsigned short id){
    Sector sector(id);
    return sector;
}

/**
 * @brief Creates a Block usign the file information and converting the file line into byte array
 * @param line
 * @return
 */
Block Utils::createBlock(string line){

    std::array<unsigned char, BLOCK_BYTES> tempBlockData = Utils::hexStringToByteArray(line);

    Block block(tempBlockData);

    return block;
}

/**
 * @brief Converts Hex string into byte array
 * @param hexStr
 * @see https://www.geeksforgeeks.org/how-to-convert-hex-string-to-byte-array-in-cpp/
 * @return
 */
std::array<unsigned char,BLOCK_BYTES> Utils::hexStringToByteArray(const std::string& hexStr){

    std::array<unsigned char, BLOCK_BYTES> byteArray = {};

    for(size_t i = 0; i < hexStr.length(); i+=2){
        string tempByteString = hexStr.substr(i,2);
        byteArray[i / 2] = static_cast<unsigned char>(std::stoi(tempByteString, nullptr, BLOCK_BYTES));
    }

    return byteArray;
}

/**
 * @brief Converts the byte vector into string
 * @param data
 * @return
 */
string Utils::byteToStr(std::vector<unsigned char> data){

    std::stringstream hexStream;

    for (unsigned char c : data){
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return hexStream.str();
}

/**
 * @brief Converts the byte into string
 * @param data
 * @return
 */
string Utils::byteToStr(unsigned char data){

    std::stringstream ss;

    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data);

    std::string str = ss.str();

    return str;
}

/**
 * @brief Utils::checkBBC
 * @note BCC: Block Check Character is a XOR calculation of all bytes
 * @see https://bcc.beyerleinf.de/
 * @param uid
 * @param bbc
 * @return
 */
bool Utils::checkBBC(std::vector<unsigned char> uid, unsigned char bbc){

    unsigned char result = 0x00;

    for (unsigned char c: uid){
        result ^= c;
    }

    if(result==bbc) return true;

    return false;
}


