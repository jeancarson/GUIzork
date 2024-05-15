#ifndef ANXIOUSCHARACTER_H
#define ANXIOUSCHARACTER_H
#include "character.h"


class anxiousCharacter : public Character
{
public:
    anxiousCharacter();
    string talk() override;
};

#endif // ANXIOUSCHARACTER_H
