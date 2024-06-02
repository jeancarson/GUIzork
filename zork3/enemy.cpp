#include "enemy.h"
#include <string>
#include <iostream>
using namespace std;
Enemy::Enemy(std::string name, Item itemToOvercome)
    //initialiser list
    : name(name), itemToOvercome(itemToOvercome) {
    cout<<("Demonstration of the object construction sequence: This (Enemy " + name + " ) will print second")<<endl;
}

//getters will not modify the enemy attribute
Item Enemy::getItemToOvercome() const{
    return itemToOvercome;
}

string Enemy::getName() const{
    return name;
}






