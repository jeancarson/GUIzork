#include "enemy.h"
#include <string>
using namespace std;
Enemy::Enemy(std::string name, Item itemToOvercome,string pathToImage, int xLoc, int yLoc)
    : name(name), itemToOvercome(itemToOvercome),pathToImage(pathToImage), xLoc(xLoc), yLoc(yLoc) {
}


Item Enemy::getItemToOvercome(){
    return itemToOvercome;
}

string Enemy::getName(){
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


