#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "Room.h"
#include "Timer.h"
#include "threateningcharacter.h"
#include "curiouscharacter.h"
#include "logger.h"
using namespace std;

#include <QObject> // Include QObject for signal-slot mechanism
#include "Timer.h"
#include "inventorybackend.h"
class GameSetUp
{
private:
    Room *currentRoom;
    Item *currentItem;
    void printWelcome();
    void showMap();
    Timer* timerWidget;
    inventoryBackEnd *inventory;
    string LoggerFile = "C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Logs.txt";
    Logger<Item> itemLogger;
    Logger<Room> roomLogger;


signals:
    void backgroundImageChanged();

public:
    void createRoomsAndItems();
    Timer* getTimer();
    GameSetUp();
    void play();
    void move(string direction);
    Room* getCurrentRoom();
    Item* getCurrentItem();
    void setCurrentItem(Item item);
    void initialiseTimerWidget();
    vector<Item> getItemsBackEnd();
    inventoryBackEnd* getInventory();
    bool isTheGameWon();



};

#endif // GAMESETUP_H
