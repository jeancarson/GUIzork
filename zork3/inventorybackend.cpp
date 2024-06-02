#include "inventorybackend.h"
#include <algorithm>

using namespace std;
inventoryBackEnd::inventoryBackEnd() {
    items.reserve(MAX_ITEMS);
}




void inventoryBackEnd:: addToInventory(Item& item){
    if (items.size() < MAX_ITEMS) {
        items.push_back(item);
    }
    // inventoryFrontEnd->updateInventoryWidget(items);

    return;
}
//references
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


bool inventoryBackEnd::isThisInTheInventory(string itemName){
    //using references
    for (Item& item : items) {
    if (item.getName() == itemName) {
        return true;
    }}
    return false;
}









