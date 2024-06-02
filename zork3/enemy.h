#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "item.h"

class Enemy
{
public:
    Enemy(std::string name = "", Item itemToOvercome = Item());
    string getName() const;
    Item getItemToOvercome () const;

    virtual ~Enemy() {}

private:
    string name;
    Item itemToOvercome;


};

#endif // ENEMY_H
