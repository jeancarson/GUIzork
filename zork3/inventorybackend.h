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
    //can be evaluated at compile time
    static constexpr int MAX_ITEMS = 2;
    //vector = dynamic list, std::list = double linked list
    vector<Item> items;

};

#endif // INVENTORYBACKEND_H
