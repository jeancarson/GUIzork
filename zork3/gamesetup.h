#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "Room.h"
#include "Timer.h"
using namespace std;

#include <QObject> // Include QObject for signal-slot mechanism
#include "Timer.h"
class GameSetUp
{
private:
    Room *currentRoom;
    void printWelcome();
    void showMap();
    void createItems();
    void displayItems();
    Timer* timerWidget;
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


};

#endif // GAMESETUP_H
