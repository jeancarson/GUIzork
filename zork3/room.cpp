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

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}
string Room::getDescription() const {
    return description;
}
// string Room::exitString() {
//     string returnString = "\nexits =";
//     for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
//         // Loop through map
//         returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
//     return returnString;
// }

Room* Room::getNextRoom(string direction) {
    if (exits.find(direction) != exits.end()) {
        // Direction exists in exits map, return the pointer to the corresponding room
        return exits[direction];
    } else {
        // Direction does not exist, handle accordingly
        return nullptr;
    }
}

void Room:: setCoordinates(int x, int y, int z){
    //AHHHHHHHHHHHH why can't c++ do arrays like normal things silly silly language
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

//TODO make this a null ptr check on all shit
void Room:: removeEnemyFromRoom(){
    enemyInRoom = new Enemy();
    this->isEnemyInRoom = false;
}


//operator overloading
bool Room::operator==(const Room& other) const {
    return this->getDescription() == other.getDescription();
}



