#include "room.h"
//sorry chris i stole a lot of your code here but no point doing it twice
Room::Room(string description) {
    this->description = description;
}

void Room::setPathToImage(string path){
    this->pathToImage = path;
}
string Room::getPathToImage(){
    return pathToImage;
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
string Room::getDescription() {
    return description;
}
string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

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
    coordinates[2] = z;
}


std::array<int, 3> Room::getCoordinates() {
    return {coordinates[0], coordinates[1], coordinates[2]};
}




