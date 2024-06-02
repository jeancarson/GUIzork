#include "threateningcharacter.h"
#include <iostream>
threateningCharacter::threateningCharacter(string name, Item itemToOvercome, string pathToImage)
    : Character(pathToImage), // Initialize Character part
    Enemy(name, itemToOvercome){ // Initialize Enemy part
    cout<<"Demonstration of the object construction sequence: This (threateningCharacter " + getPathToImage() + ") will print third"<<endl;
}

string threateningCharacter::talk(){
    return "NO WAY I'M \nLETTING YOU \nIN HERE!!!!!!";
}
