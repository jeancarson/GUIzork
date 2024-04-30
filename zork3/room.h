#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>
// #include "item.h"
using namespace std;
using std::vector;class Room {

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    // vector <Item> itemsInRoom;


public:
    // int numberOfItems();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string Description();
    //image
    //items





    // string longDescription();
    // Room* nextRoom(string direction);
    // void addItem(Item *inItem);
    // string displayItem();
    // int isItemInRoom(string inString);
    // void removeItemFromRoom(int location);
};

#endif
