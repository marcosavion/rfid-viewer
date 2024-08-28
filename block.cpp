#include "block.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "constants.h"
using namespace std;


/**
 * @brief Returns the 16 byte array
 * @return unsigned char array data
 */
std::array<unsigned char, BLOCK_BYTES> Block::getData(){
    return this->data;
}

/**
 * @brief Converts the Block object into string data
 * @return string data
 */
string Block::toString(){
    return byteToStr();
}



/**
 * @brief Converts the 16 byte array into string
 * @return data string
 */
string Block::byteToStr(){

    std::stringstream hexStream;

    for (unsigned char c : this->data){
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);

    }

    return hexStream.str();
}








