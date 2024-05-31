#include "anxiouscharacter.h"

anxiousCharacter::anxiousCharacter(string pathToImage) {
    this->pathToImage = pathToImage;
}


string anxiousCharacter:: talk(){
    return "Hurry up\n!!!!!!!";
}

string anxiousCharacter::getPathToImage(){
    return pathToImage;
}
