#include "room.h"
//sorry chris i stole your code here but no point doing it twice
Room::Room(string description) {
    this->description = description;
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
string Room::getPathToImage(){
    return pathToImage;
}

Room& Room::getNextRoom(string direction){
    return exits[direction][0];
}
