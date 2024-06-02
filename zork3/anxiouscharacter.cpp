#include "anxiouscharacter.h"

AnxiousCharacter::AnxiousCharacter(std::string pathToImage) :
    Character(pathToImage){}

std::string AnxiousCharacter::talk() {
    return "Hurry up\n!!!!!!!";
}
