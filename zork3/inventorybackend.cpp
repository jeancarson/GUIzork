#include "inventorybackend.h"
#include <algorithm>

using namespace std;
inventoryBackEnd::inventoryBackEnd() {
    items.reserve(MAX_ITEMS);
}


Item inventoryBackEnd:: getItem(Item item){
    currentItem = item;
    return currentItem;
}

void inventoryBackEnd:: addToInventory(Item item){
    if (items.size() < MAX_ITEMS) {
        items.push_back(item);
    }
    // inventoryFrontEnd->updateInventoryWidget(items);

    return;
}

void inventoryBackEnd::removeFromInventory(const Item& item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
    // inventoryFrontEnd->updateInventoryWidget(items);
}


vector<Item> inventoryBackEnd::getInventory(){
    return items;
}









