#include "curiouscharacter.h"
#include <iostream>


CuriousCharacter::CuriousCharacter(string name, Item itemToOvercome, string pathToImage)
    : Character(pathToImage), // Initialize Character part
    Enemy(name, itemToOvercome){ // Initialize Enemy part
                                cout<<"Demonstration of the object construction sequence: This (CuriousCharacter " + getPathToImage() + " will print third"<<endl;
}

string CuriousCharacter::talk(){
    return "I lost something! \nCanyou help \nme find it?";
}
