#include "tag.h"
#include "constants.h"

/**
 * @brief Adds a sector object to this tag
 * @param sector
 */
void Tag::addSector(Sector sector){
    this->data.push_back(sector);
}

/**
 * @brief Gets the sector with this particular id
 * @param id
 * @return Returns the particular sectors with the specified id
 */
Sector& Tag::getSector(unsigned short id){
    return this->data.at(id);
}

/**
 * @brief Returns sector vector with all tag data
 * @return Returns all Tag data
 */
std::vector<Sector> Tag::getData(){
    return this->data;
}


/**
 * @brief Gets the Tag UID
 * @note Generally, all tags have 4 byte UID but they can have 7 byte UID
 * @return A vector with UID in bytes
 */
std::vector<unsigned char> Tag::getUID(){

    std::array<unsigned char, BLOCK_BYTES> blockData = this->data.at(0).getBlock(0).getData();

    std::vector<unsigned char> vec(blockData.begin(), blockData.begin()+UID_TAG_LENGTH);

    return vec;
}


/**
 * @brief Gets the Tag BCC
 * @note BCC: Block Check Character is a XOR calculation of all bytes
 *      Tag UID is following by BCC, so we can just get the next byte (fith byte)
 * @see https://bcc.beyerleinf.de/
 * @return The Tag BBC byte
 */
unsigned char Tag::getBCC(){

    std::array<unsigned char, BLOCK_BYTES> blockData = this->data.at(0).getBlock(0).getData();

    unsigned char bbc = blockData[BCC_BYTE];

    return bbc;
}

/**
 * @brief Get the rest of the manufacturer data
 * @return vector with this manufacturar information
 */

std::vector<unsigned char> Tag::getManufacturerData(){

    std::array<unsigned char, BLOCK_BYTES> blockData = this->data.at(0).getBlock(0).getData();

    std::vector<unsigned char> vec(blockData.begin()+BCC_BYTE + 1, blockData.end());

    return vec;
}
