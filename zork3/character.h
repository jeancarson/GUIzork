#ifndef CHARACTER_H
#define CHARACTER_H

#include "string"

using namespace std;



class Character {
public:
    Character(string PathToImage);
    virtual ~Character();

    // Pure virtual function because of =0, therefore an abstract class
    virtual std::string talk() = 0;

    std::string getPathToImage() const;
    //uisng protected ACCESS SPECIFIER
protected:
    std::string pathToImage;
};
#endif // CHARACTER_H
