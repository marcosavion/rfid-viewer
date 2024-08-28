#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <string>

//Block consts
const unsigned short BLOCK_BYTES = 16;

//Sector consts
const unsigned short SECTOR_LENGTH = 16;
const unsigned short SECTOR_TRAILER_BLOCK = 3;
const unsigned short KEY_A_LENGTH = 6;
const unsigned short ACCESS_BIT_LENGTH = 4;
const std::string INVALID_STRING_SECTOR = "----------------";

//Tag consts
const unsigned short UID_TAG_LENGTH = 4;
const unsigned short BCC_BYTE = UID_TAG_LENGTH;
const unsigned short MAX_SECTORS = 16;

#endif // CONSTANTS_H
