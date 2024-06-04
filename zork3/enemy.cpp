#include "enemy.h"
#include <string>
#include <iostream>
using namespace std;
Enemy::Enemy(std::string name, Item itemToOvercome)
    //initialiser list
    : name(name), itemToOvercome(itemToOvercome) {
    //To show the object construction sequence - demonstration purposes only
    cout<<("Demonstration of the object construction sequence: This (Enemy " + name + " ) will print second")<<endl;
}

//const - getters will not modify the enemy attribute
Item Enemy::getItemToOvercome() const{
    return itemToOvercome;
}

string Enemy::getName() const{
    return name;
}






