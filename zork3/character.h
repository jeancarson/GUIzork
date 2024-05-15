#ifndef CHARACTER_H
#define CHARACTER_H

#include "string"

using namespace std;



class Character

{
public:
    Character();
    virtual string talk();

    virtual ~Character() {};
};

#endif // CHARACTER_H
