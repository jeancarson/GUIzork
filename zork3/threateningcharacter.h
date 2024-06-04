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
    threateningCharacter(string name, Item ItemToOvercome, string pathToImage);
    //overriding from character class
    string talk() override;
};

#endif // THREATENINGCHARACTER_H
