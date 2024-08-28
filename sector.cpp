#include "sector.h"
#include <array>
#include "block.h"
#include "constants.h"

/**
 * @brief Adds a new block to this sector
 * @param newBlock
 */
void Sector::addBlock(Block newBlock){
    this->data.push_back(newBlock);
}

/**
 * @brief Returns the desired block of a particular sector
 * @param blockID
 * @return particular block object
 */
Block Sector::getBlock(unsigned short blockID){
    try{
        return this->data.at(blockID);
    }
    catch (...){
        cout << "error, there is not block id";
        return this->data.at(0);
    }
}

/**
 * @brief Returns the entire block vector of this particular sector
 * @return all sector blocks
 */
std::vector<Block> Sector::getBlocks(){
    return this->data;
}


/**
 * @brief Retruns the id of this sector
 * @return sector id
 */
unsigned short Sector::getID(){
    return this->id;
}

/**
 * @brief Returns the id of this sector in string format
 * @return sector id in string format
 */
string Sector::getIDStr(){
    return to_string(this->getID());
}



/**
 * @brief Gets the Key A of this sector
 * @note Key A is at the begging of the sector and its length is 6 bytes
 * @return returns the key A in a vector
 */
std::vector<unsigned char> Sector::getPasswordA(){

    std::array<unsigned char, 16> blockData = this->data.at(SECTOR_TRAILER_BLOCK).getData();

    std::vector<unsigned char> vec(blockData.begin(), blockData.begin()+KEY_A_LENGTH);

    return vec;
}

/**
 * @brief Gets the Key B of this sector
 * @note Key B is at the ending of the sector and its length is 6 bytes
 * @return returns the key B in a vector
 */
std::vector<unsigned char> Sector::getPasswordB(){

    std::array<unsigned char, 16> blockData = this->data.at(SECTOR_TRAILER_BLOCK).getData();

    std::vector<unsigned char> vec(blockData.begin()+KEY_A_LENGTH+ACCESS_BIT_LENGTH, blockData.end());

    return vec;
}

/**
 * @brief Gets the Access Bit of this sector
 * @note Access bits are 4 bytes between Key A and Key B
 * @return returns the access bits in a vector
 */
std::vector<unsigned char> Sector::getAccessBits(){

    std::array<unsigned char, 16> blockData = this->getBlock(SECTOR_TRAILER_BLOCK).getData();

    std::vector<unsigned char> vec(blockData.begin()+KEY_A_LENGTH, blockData.begin()+KEY_A_LENGTH+ACCESS_BIT_LENGTH);

    return vec;
}

bool Sector::isValid(){
    if(this->data.empty()){
        return false;
    }else{
        return true;
    }


}

