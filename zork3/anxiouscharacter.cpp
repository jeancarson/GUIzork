#include "anxiouscharacter.h"

AnxiousCharacter::AnxiousCharacter(std::string pathToImage) {
    this->pathToImage = pathToImage;
}

std::string AnxiousCharacter::talk() {
    return "Hurry up\n!!!!!!!";
}
