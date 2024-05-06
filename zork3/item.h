#ifndef ITEM_H
#define ITEM_H

#include <QString>

using namespace std;
class Item
{
public:
    Item();
    QString getPathToImage();
    bool operator==(const Item& other) const {
        return this->name == other.name;
    }

private:
    string description;
    string pathToImage;
    bool collected;
    bool inUse;
    bool inIventory;
    string name;
};





#endif // ITEM_H
