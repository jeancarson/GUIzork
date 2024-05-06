#ifndef INVENTORYBACKEND_H
#define INVENTORYBACKEND_H

#include "inventory.h"

#include "item.h"
#include <vector>

class inventoryBackEnd
{
public:
    inventoryBackEnd(Inventory* inventory);
    std::vector<Item> items;


private:
    static constexpr int MAX_ITEMS = 2; // Example maximum number of items
    Item currentItem;
    Item getItem(Item item);
    void addToInventory(Item item);
    void removeFromInventory(const Item& item);
    Inventory* inventoryFrontEnd;

};

#endif // INVENTORYBACKEND_H
