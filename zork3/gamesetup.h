#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "Room.h"
#include "Timer.h"
#include "threateningcharacter.h"
#include "curiouscharacter.h"
#include "logger.h"
#include "customexceptions.h"
using namespace std;

// #include <QObject>
#include "Timer.h"
#include "inventorybackend.h"

//Namespaces
namespace GameSetup {

class GameSetUp
{
#ifdef DEBUG_MODE
public:
    void moveDEBUG(string direction);

#else
public:
    void move(string direction);

#endif

private:
    Room *currentRoom;
    Item *currentItem;
    Timer* timerWidget;
    inventoryBackEnd *inventory;



public:
    Timer* getTimer();
    GameSetUp();
    ~GameSetUp();
    Room* getCurrentRoom();
    Item* getCurrentItem();
    void setCurrentItem(const Item& item);
    void initialiseTimerWidget();
    vector<Item> getItemsBackEnd();
    inventoryBackEnd* getInventory();
    bool isTheGameWon();
    void createRoomsAndItems();


};}

#endif // GAMESETUP_H
