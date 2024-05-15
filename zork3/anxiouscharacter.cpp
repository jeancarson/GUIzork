#include "anxiouscharacter.h"

anxiousCharacter::anxiousCharacter(string pathToImage) {
    this->pathToImage = pathToImage;
}


string anxiousCharacter:: talk(){
    return "OOH Hurry up!! Time is running out!";
}

string anxiousCharacter::getPathToImage(){
    return pathToImage;
}
