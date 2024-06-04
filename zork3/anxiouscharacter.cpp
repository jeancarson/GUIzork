#include "anxiouscharacter.h"

AnxiousCharacter::AnxiousCharacter(string pathToImage) :
    //inheriting this attribute from character
    Character(pathToImage){}

std::string AnxiousCharacter::talk() {
    return "Hurry up\n!!!!!!!";
}
