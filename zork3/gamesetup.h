#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "Room.h"
using namespace std;

#include <QObject> // Include QObject for signal-slot mechanism

class GameSetUp
{
private:
    Room *currentRoom;
    void printWelcome();
    void showMap();
    void createItems();
    void displayItems();

signals:
    void backgroundImageChanged();

public:
    void createRooms();

    GameSetUp();
    void play();
    void move(string direction);
    Room* getCurrentRoom();
};

#endif // GAMESETUP_H
