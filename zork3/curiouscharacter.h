#ifndef CURIOUSCHARACTER_H
#define CURIOUSCHARACTER_H
#include "character.h"
#include "enemy.h"


//Multiple Inheritence
class CuriousCharacter : public Character, public Enemy
{
public:
    CuriousCharacter(string name, Item itemToOvercome, string pathToImage);
    string talk() override;
};

#endif // CURIOUSCHARACTER_H
