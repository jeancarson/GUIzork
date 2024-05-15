#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"

using namespace std;

using std::vector;class Room {

private:

    string description;
    map<string, Room*> exits;
    string exitString();
    string pathToImage;
    //not sure if this is right idk how to do arrays in c++
    std::array<int, 3> coordinates;
    vector <Item> itemsInRoom;
    Enemy* enemyInRoom;

public:
    // int numberOfItems();
    Room(string description);

    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getDescription();
    string getPathToImage();
    Room* getNextRoom(string direction); // Corrected return type to Room*
    void setPathToImage(string path);
    void setCoordinates(int x, int y, int z);
    const std::array<int, 3>& getCoordinates();

    vector<Item> getItemsInRoom();
    void addItemToRoom(Item item);
    void removeItemFromRoom(Item item);

    Enemy* getEnemyInRoom();
    void setEnemyInRoom(Enemy *enemy);
    void removeEnemyFromRoom();
    bool isEnemyInRoom;
};


    //image
    //items





    // string longDescription();
    // Room* nextRoom(string direction);
    // void addItem(Item *inItem);
    // string displayItem();
    // int isItemInRoom(string inString);
    // void removeItemFromRoom(int location);


#endif
