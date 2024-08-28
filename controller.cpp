#include "controller.h"
#include "tag.h"
#include "utils.h"

/**
 * @brief Sets the tag attribute to the given one
 * @param tag
 */
void Controller::setTag(Tag tag){
    this->tag = tag;
}

/**
 * @brief This method is a facade of Utils OpenFile() method.
 *        When a file is open successfully, a Tag is create using the file information
 * @param filePathName
 */
void Controller::openFile(string filePathName){

    Tag tag = Utils::openFile(filePathName);

    this->setTag(tag);
}

/**
 * @brief Gets the Tag UID from the current tag and converts bytes into string
 * @return A string with Tag UID
 */
string Controller::getUID(){

    if(this->tag.getUID().empty()){
        return "ERROR";
    }
    return Utils::byteToStr(this->tag.getUID());
}

/**
 * @brief Gets the BCC from tag information and converts the byte into string
 * @return A string with BCC information
 */
string Controller::getBCC(){
    return Utils::byteToStr(this->tag.getBCC());
}


/**
 * @brief Checks if the BCC value is correct
 * @return True if the BCC is rigth. False otherwise
 */
bool Controller::checkBCC(){
    if(Utils::checkBBC(this->tag.getUID(), this->tag.getBCC()))
        return true;
    else
        return false;
}


/**
 * @brief Gets the manufacturer data
 * @return A string with all manufacturer data
 */
string Controller::getManufacturerData(){
    return Utils::byteToStr(this->tag.getManufacturerData());
}

/**
 * @brief Returns all the sector information within this Tag
 * @return Vector with all sector information
 */
std::vector<Sector> Controller::getTagData(){
    return this->tag.getData();
}


/**
 * @brief Gets a particular sector by using its sector number
 * @param sectorNumber
 * @return A sector object with this id
 */
Sector Controller::getSector(unsigned short sectorNumber){
    return this->tag.getSector(sectorNumber);
}

/**
 * @brief Gets the Key A bytes and converts it into string data
 * @param sectorNumber
 * @return A string with all Key A information
 */
string Controller::getPasswordA(unsigned short sectorNumber){
    return Utils::byteToStr(this->tag.getSector(sectorNumber).getPasswordA());
}

/**
 * @brief Gets the Key B bytes and converts it into string data
 * @param sectorNumber
 * @return A string with all Key B information
 */
string Controller::getPasswordB(unsigned short sectorNumber){
    return Utils::byteToStr(this->tag.getSector(sectorNumber).getPasswordB());
}

/**
 * @brief Gets the access bits in bytes and converts it into string data
 * @param sectorNumber
 * @return A string with all access bits information
 */
string Controller::getAccessBits(unsigned short sectorNumber){
    return Utils::byteToStr(this->tag.getSector(sectorNumber).getAccessBits());
}







