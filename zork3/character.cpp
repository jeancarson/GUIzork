#include "character.h"
#include <iostream>
using namespace std;

Character::Character(string PathToImage) {
    this->pathToImage = PathToImage;
    cout<<"Demonstration of object construction sequence. This (Character " + getPathToImage() + " will print first"<<endl;
}

Character::~Character() {}

std::string Character::getPathToImage() const {
    return pathToImage;
}



