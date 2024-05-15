#ifndef ANXIOUSCHARACTER_H
#define ANXIOUSCHARACTER_H
#include "character.h"


class anxiousCharacter : public Character
{
public:
    anxiousCharacter(string pathToImage);
    string talk() override;
    string getPathToImage();

private:
    string pathToImage;
};

#endif // ANXIOUSCHARACTER_H
