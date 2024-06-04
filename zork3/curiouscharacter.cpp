#include "curiouscharacter.h"
#include <iostream>


CuriousCharacter::CuriousCharacter(string name, Item itemToOvercome, string pathToImage)
    // Initialise Character part
    : Character(pathToImage),
    // Initialise Enemy part
    Enemy(name, itemToOvercome){
    cout<<"Demonstration of the object construction sequence: This (CuriousCharacter " + getPathToImage() + " will print third"<<endl;
}

string CuriousCharacter::talk(){
    return "I lost something! \nCanyou help \nme find it?";
}
