#ifndef ANXIOUSCHARACTER_H
#define ANXIOUSCHARACTER_H
#include "character.h"


class AnxiousCharacter : public Character {
public:
    AnxiousCharacter(std::string pathToImage);
    //This is a virtual function that must be overriden by subclasses
    std::string talk() override;
};

#endif // ANXIOUSCHARACTER_H
