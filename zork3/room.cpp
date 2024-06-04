#include "room.h"
//sorry chris i stole a lot of your code here but no point doing it twice
Room::Room(string description)
    : description(description), isEnemyInRoom(false), enemyInRoom(nullptr) {}

// Copy constructor using initializer list
Room::Room(const Room& other)
    : description(other.description),
    enemyInRoom(other.enemyInRoom),
    isEnemyInRoom(other.isEnemyInRoom),
    itemsInRoom(other.itemsInRoom),
    coordinates(other.coordinates),
    exits(other.exits),
    pathToImage(other.pathToImage) {}

void Room::setPathToImage(string path){
    this->pathToImage = path;
}
string Room::getPathToImage(){
    return this->pathToImage;
}

//indexing the array with the Direction enum
void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
        exits[NORTH] = north;
        exits[EAST] = east;
        exits[SOUTH] = south;
        exits[WEST] = west;
}
string Room::getDescription() const {
    return description;
}


Room* Room::getNextRoom(Direction direction) {
    return exits[direction];
    }


void Room:: setCoordinates(int x, int y, int z){
    coordinates[0] = x;
    coordinates[1] = y;
    if ( z ==0 || z==1){
        coordinates[2] = z;}
}


const std::array<int, 3>& Room::getCoordinates() {
    return coordinates;
}



vector<Item> Room:: getItemsInRoom(){
    return itemsInRoom;
}

void Room:: addItemToRoom(Item item){
    itemsInRoom.push_back(item);
}

void Room::removeItemFromRoom(Item item){
    auto it = std::find(itemsInRoom.begin(), itemsInRoom.end(), item);
    if (it != itemsInRoom.end()) {
        itemsInRoom.erase(it);
    }
}
Enemy* Room::getEnemyInRoom() {
    return enemyInRoom;
}
void Room::setEnemyInRoom(Enemy *enemy){
    enemyInRoom = enemy;
    this->isEnemyInRoom = true;
}

void Room:: removeEnemyFromRoom(){
    enemyInRoom = nullptr;
    this->isEnemyInRoom = false;
}


//operator overloading
bool Room::operator==(const Room& other) const {
    return this->getDescription() == other.getDescription();
}



