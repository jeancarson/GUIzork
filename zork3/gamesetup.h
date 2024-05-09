#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "Room.h"
#include "Timer.h"
using namespace std;

#include <QObject> // Include QObject for signal-slot mechanism
#include "Timer.h"
#include "inventorybackend.h"
class GameSetUp
{
private:
    Room *currentRoom;
    void printWelcome();
    void showMap();
    void createItems();
    void displayItems();
    Timer* timerWidget;
    inventoryBackEnd *inventory;
signals:
    void backgroundImageChanged();

public:
    void createRooms();
    Timer* getTimer();
    GameSetUp();
    void play();
    void move(string direction);
    Room* getCurrentRoom();
    void initialiseTimerWidget();
    vector<Item> getItemsBackEnd();


};

#endif // GAMESETUP_H
