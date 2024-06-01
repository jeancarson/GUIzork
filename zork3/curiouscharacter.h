#ifndef CURIOUSCHARACTER_H
#define CURIOUSCHARACTER_H
#include "character.h"
#include "enemy.h"


//Multiple Inheritence
class CuriousCharacter : public Character, public Enemy
{
public:
    CuriousCharacter();
    string talk() override;


    using Enemy::Enemy;
};

#endif // CURIOUSCHARACTER_H
