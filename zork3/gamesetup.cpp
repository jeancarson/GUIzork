#include "gamesetup.h"
#include <iostream>

namespace GameSetup {

GameSetUp::GameSetUp() :
    itemLogger(LoggerFile),
    roomLogger(LoggerFile) {
    timerWidget = new Timer();
    this-> inventory = new inventoryBackEnd();
    createRoomsAndItems();
    currentItem = new Item();
}

// }
// GameSetUp::~GameSetUp() {
//     delete currentItem;
// }


void GameSetUp::createRoomsAndItems()  {
    Room *frontDoor, *foyer, *insideLift;
    frontDoor = (new Room("Front Door"));
    frontDoor->setPathToImage(":/conor.jpg");

    foyer = (new Room("You go through the front door. \nYou see a set of stairs and a lift"));
    foyer->setPathToImage(":/frontDoorGeneric.jpg");

    insideLift = (new Room("You have entered the lift. North is first floor, west is second floor"));
    insideLift->setPathToImage(":/taylor.jpg");
    cout<<"Rooms are made"<<endl;

    Item *keycard = new Item();
    Item *umbrella = new Item();
    Item *lunchbox = new Item();
    Item *bat = new Item();
    keycard->setNameAndPathToImage("keycard", ":/Keycard.png");

    umbrella->setNameAndPathToImage("umbrella",":/umbrella.png" );

    lunchbox->setNameAndPathToImage("lunchbox",":/lunchbox.png" );
    bat->setNameAndPathToImage("bat", "");
    cout<<"Items are made"<<endl;

    frontDoor->addItemToRoom(*keycard);
    foyer->addItemToRoom(*umbrella);
    insideLift->addItemToRoom(*lunchbox);
    cout<<"items added to rooms"<<endl;

//             (N, E, S, W)
    frontDoor->setExits(foyer, NULL, NULL, NULL);
    foyer->setExits(NULL, NULL, frontDoor, insideLift);
    insideLift->setExits(NULL, foyer, NULL, NULL);

    frontDoor->setCoordinates(100, 100, 0);
    foyer -> setCoordinates(150, 150, 0);
    insideLift -> setCoordinates(150, 150, 1);
    cout<<"coordinates set"<<endl;



    threateningCharacter *LockedDoor = new threateningCharacter("Locked Door", *keycard,":/MIA.png", 400, 300);
    CuriousCharacter *Mia = new CuriousCharacter("Mia", *umbrella,":/MIA.png", 200, 500);
    CuriousCharacter *Ruan = new CuriousCharacter("Ruan", *bat, ":/Keycard.png",400, 700);

    frontDoor->setEnemyInRoom(LockedDoor);
    insideLift->setEnemyInRoom(Mia);


    this->currentRoom = frontDoor;
    cout<<currentRoom->getDescription();

}



Room* GameSetUp::getCurrentRoom() {
    return currentRoom;
}

Item* GameSetUp::getCurrentItem(){
    return currentItem;
}

void GameSetUp::setCurrentItem(Item item){
    *currentItem = item;
    itemLogger.log(*currentItem);
}


void GameSetUp::move(string direction) {
    Room* nextRoomPtr = currentRoom->getNextRoom(direction);
    if (nextRoomPtr != nullptr && !(currentRoom->isEnemyInRoom)) {
        currentRoom = nextRoomPtr;
        roomLogger.log(*currentRoom);
    } else {
        cout << "You cannot move in that direction." << endl;
    }
}

bool GameSetUp::isTheGameWon(){
    bool correctItem = inventory->isThisInTheInventory("lunchbox");
    bool correctRoom = currentRoom->getDescription() == "Front Door";

    return (correctItem && correctRoom);
}













Timer* GameSetUp::getTimer(){
    return timerWidget;
}

vector<Item> GameSetUp:: getItemsBackEnd(){
    return inventory->getInventory();
}

inventoryBackEnd* GameSetUp:: getInventory(){
    return this->inventory;
}

}
