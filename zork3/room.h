#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"

using namespace std;

enum Direction { NORTH, EAST, SOUTH, WEST };


using std::vector;class Room {

private:

    string description;
    array<Room*, 4> exits;
    string pathToImage;
    //not sure if this is right idk how to do arrays in c++
    std::array<int, 3> coordinates;
    vector <Item> itemsInRoom;
    Enemy* enemyInRoom;

public:
    Room(string description);
    //copy contructor
    Room(const Room& other);
    //operator overloading
    bool operator==(const Room& other) const;

    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getDescription() const;
    string getPathToImage();
    Room* getNextRoom(Direction direction);
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


#endif
