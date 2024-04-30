#ifndef GAMESETUP_H
#define GAMESETUP_H


#include "Room.h"
using namespace std;


class GameSetUp
{
private:
    Room *currentRoom;
    void createRooms();
    void printWelcome();
    void showMap();
    void createItems();
    void displayItems();
public:
    GameSetUp();
    void play();
    void move();
};

#endif // GAMESETUP_H
