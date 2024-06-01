#ifndef ITEM_H
#define ITEM_H

#include <QString>

using namespace std;
class Item
{
public:

    Item();
    //copy contructor
    Item(const Item& other);
    QString getPathToImage();

    //operator overloading
    bool operator==(const Item& other) const;


    string getName() const;
    void setNameAndPathToImage(string name, string path);

private:
    string pathToImage;
    bool collected;
    bool inUse;
    bool inIventory;
    string name;
};





#endif // ITEM_H
