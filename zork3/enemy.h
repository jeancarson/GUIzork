#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "item.h"
using namespace std;
class Enemy
{
public:
    Enemy(std::string name = "", Item itemToOvercome = Item());
    string getName() const;
    Item getItemToOvercome () const;
//Virtual destructor to ensure the destructors of derived classes are also called when an enemy is deleted
    virtual ~Enemy() {}

private:
    string name;
    Item itemToOvercome;


};

#endif // ENEMY_H
