#include "enemy.h"
#include <string>
using namespace std;
Enemy::Enemy(std::string name, Item itemToOvercome,string pathToImage, int xLoc, int yLoc)
    : name(name), itemToOvercome(itemToOvercome),pathToImage(pathToImage), xLoc(xLoc), yLoc(yLoc) {
}

//getters will not modify the enemy attribute
Item Enemy::getItemToOvercome() const{
    return itemToOvercome;
}

string Enemy::getName() const{
    return name;
}

int Enemy:: getXLoc(){
    return xLoc;
}

int Enemy::getYLoc(){
    return yLoc;
}

string Enemy::getPathToImage(){
    return pathToImage;
}


