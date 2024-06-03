#ifndef INVENTORYBACKEND_H
#define INVENTORYBACKEND_H


#include "item.h"
#include <vector>

using namespace std;

class inventoryBackEnd
{
public:
    inventoryBackEnd();
    //more references
    void addToInventory(Item& item);
    void removeFromInventory(const Item& item);
    vector<Item> getInventory();
    bool isThisInTheInventory(string itemName);


private:
    //TODO
    static constexpr int MAX_ITEMS = 2;

    vector<Item> items;

};

#endif // INVENTORYBACKEND_H
