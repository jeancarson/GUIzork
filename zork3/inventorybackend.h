#ifndef INVENTORYBACKEND_H
#define INVENTORYBACKEND_H


#include "item.h"
#include <vector>

using namespace std;

class inventoryBackEnd
{
public:
    inventoryBackEnd();
    Item getItem(Item item);
    void addToInventory(Item item);
    void removeFromInventory(const Item& item);
    vector<Item> getInventory();


private:
    static constexpr int MAX_ITEMS = 2; // Example maximum number of items
    Item currentItem;

    vector<Item> items;

};

#endif // INVENTORYBACKEND_H
