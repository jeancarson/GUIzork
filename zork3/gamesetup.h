#ifndef GAMESETUP_H
#define GAMESETUP_H


#include "Room.h"
using namespace std;


class GameSetUp
{
private:
    Room *currentRoom;
    void printWelcome();
    void showMap();
    void createItems();
    void displayItems();
public:
    void createRooms();

    GameSetUp();
    void play();
    void move(string direction);
    Room getCurrentRoom();
};

#endif // GAMESETUP_H
