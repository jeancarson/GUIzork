#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "item.h"

class Enemy
{
public:
    Enemy(std::string name = "", Item itemToOvercome = Item(), string pathToImage="", int xLoc = 0, int yLoc = 0);
    string getName();
    Item getItemToOvercome();
    int getXLoc();
    int getYLoc();
    string getPathToImage();
    virtual ~Enemy() {}

private:
    string name;
    Item itemToOvercome;
    string pathToImage;
    int xLoc;
    int yLoc;

};

#endif // ENEMY_H
