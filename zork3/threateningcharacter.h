#ifndef THREATENINGCHARACTER_H
#define THREATENINGCHARACTER_H

#include "character.h"
#include "enemy.h"
#include <string>
using namespace std;
//Multiple Inheritence
class threateningCharacter : public Character, public Enemy
{
public:
    // threateningCharacter();
    using Enemy::Enemy;
    string talk() override;
};

#endif // THREATENINGCHARACTER_H
