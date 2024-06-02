#include "gamesetup.h"
#include <iostream>

namespace GameSetup {

GameSetUp::GameSetUp():
    // : itemLogger(LoggerFile)
    // , roomLogger(LoggerFile)
     currentItem(nullptr)
{
    timerWidget = new Timer();
    inventory = new inventoryBackEnd();
    createRoomsAndItems();
    currentItem = new Item();
}


GameSetUp::~GameSetUp() {
    delete currentItem;
    delete inventory;
    delete timerWidget;
}


void GameSetUp::createRoomsAndItems()  {
    Room *frontDoor, *foyer, *insideLift, *upstairsFoyer, *coworkingSpace1, *kitchen, *coworkingSpace2;
    Room *coworkingSpace3a, *coworkingSpace3b, *forestRoom, *studio2;
    frontDoor = (new Room("Front Door"));
    frontDoor->setPathToImage(":/ISEFrontDoor.jpg");

    foyer = (new Room("You go through the front door. \nYou see a set of stairs and a lift"));
    foyer->setPathToImage(":/ISEFoyer.jpg");

    insideLift = (new Room("You have entered the lift. North is first floor, west is second floor"));
    insideLift->setPathToImage(":/ISEInsideLift.jpg");

    upstairsFoyer = new Room ("You have reached upstairs");
    upstairsFoyer->setPathToImage(":/ISEUpstairsFoyer.jpg");

    coworkingSpace1 = new Room("In the coworking space outside TA office");
    coworkingSpace1->setPathToImage(":/ISECoworkingSpace1.jpg");

    coworkingSpace2 = new Room("By the coworking booths");
    coworkingSpace2->setPathToImage(":/ISECoworkingSpace.jpg");

    kitchen = new Room("In the kitchen");
    kitchen->setPathToImage(":/ISEKitchen.jpg");

    coworkingSpace3a = new Room ("At that tall table outside Ian and Marks office");
    coworkingSpace3a->setPathToImage(":/ISECoworkingSpace3a.jpg");

    coworkingSpace3b = new Room ("Outside Alison's office");
    coworkingSpace3b->setPathToImage(":/ISECoworkingSpace3b.jpg");

    forestRoom = new Room ("The forest room..duh");
    forestRoom ->setPathToImage(":/ISEForestRoom.jpg");

    studio2 = new Room ("Studio off the forest room");
    studio2->setPathToImage(":/ISEStudio.jpg");


    //             (N, E, S, W)
    frontDoor->setExits(foyer, NULL, NULL, NULL);
    foyer->setExits(NULL, NULL, frontDoor, insideLift);
    insideLift->setExits(upstairsFoyer, NULL, foyer, NULL);
    upstairsFoyer->setExits(NULL, studio2, insideLift, coworkingSpace1);
    coworkingSpace1->setExits(kitchen, upstairsFoyer, coworkingSpace2, NULL);
    coworkingSpace2->setExits(coworkingSpace3a, NULL, coworkingSpace1, NULL);
    kitchen->setExits(studio2, NULL, coworkingSpace1, NULL);
    coworkingSpace3a->setExits(NULL, NULL, coworkingSpace2, coworkingSpace3b);
    coworkingSpace3b->setExits(NULL, coworkingSpace3a, NULL, forestRoom);
    forestRoom->setExits(NULL, studio2, NULL, coworkingSpace3b);
    studio2->setExits(NULL, NULL, forestRoom, kitchen);

    //coordinates are X, Y, Floor (0 or 1)
    frontDoor->setCoordinates(415, 430, 0);
    foyer -> setCoordinates(415, 360, 0);
    insideLift -> setCoordinates(365, 330, 0);
    upstairsFoyer -> setCoordinates(470, 350, 1);
    coworkingSpace1 -> setCoordinates(515, 350, 1);
    coworkingSpace2 -> setCoordinates(470, 300, 1);
    kitchen -> setCoordinates(460, 410, 1);
    coworkingSpace3a -> setCoordinates(430, 250, 1);
    coworkingSpace3b -> setCoordinates(350, 250, 1);
    forestRoom -> setCoordinates(300, 300, 1);
    studio2 -> setCoordinates(200, 350, 1);

    cout<<"coordinates set"<<endl;


//remvoing from here
    Item *keycard = new Item();
    Item *umbrella = new Item();
    Item *lunchbox = new Item();
    Item *fish = new Item();
    keycard->setNameAndPathToImage("keycard", ":/Keycard.png");
    umbrella->setNameAndPathToImage("umbrella",":/umbrella.png" );
    lunchbox->setNameAndPathToImage("lunchbox",":/lunchbox.png" );
    fish->setNameAndPathToImage("fish", ":/RuansFish.png");
    cout<<"Items are made"<<endl;

    frontDoor->addItemToRoom(*keycard);
    coworkingSpace1->addItemToRoom(*umbrella);
    coworkingSpace3a->addItemToRoom(*fish);
    forestRoom->addItemToRoom(*lunchbox);
    cout<<"items added to rooms"<<endl;





    threateningCharacter *LockedDoor = new threateningCharacter("Locked Door", *keycard,":/SecurityGuard.png");
    CuriousCharacter *Mia = new CuriousCharacter("Mia", *umbrella,":/MIA.png");
    CuriousCharacter *Ruan = new CuriousCharacter("Ruan", *fish, ":/RUAN.png");

    frontDoor->setEnemyInRoom(LockedDoor);
    coworkingSpace1->setEnemyInRoom(Mia);
    coworkingSpace3a->setEnemyInRoom(Ruan);

//removing to here

    this->currentRoom = frontDoor;
    cout<<currentRoom->getDescription();
}



Room* GameSetUp::getCurrentRoom() {
    return currentRoom;
}

Item* GameSetUp::getCurrentItem(){
    return currentItem;
}

void GameSetUp::setCurrentItem(const Item& item) {
    *currentItem = item; // Uses the custom copy constructor
    itemLogger.log(*currentItem);
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







#ifdef DEBUG_MODE
void GameSetUp::moveDEBUG(std::string direction) {
    try {
        Room* nextRoomPtr = currentRoom->getNextRoom(direction);
        if (nextRoomPtr == nullptr) {
            cout<<"No Move occcured - No room in that direction"<<endl;
            throw invalidRoomMoveException();
        }
        if (currentRoom->isEnemyInRoom) {
            cout<<"No move occured - enemy present in room"<<endl;
            throw UndefeatedEnemyInRoomException();
        }
        currentRoom = nextRoomPtr;
        cout<<"currentRoom asigned: "+ currentRoom->getDescription();
        roomLogger.log(*currentRoom);
    } catch (const invalidRoomMoveException& e) {
        std::cerr << "Invalid room move: " << e.what() << std::endl;
    } catch (const UndefeatedEnemyInRoomException& e) {
        std::cerr << "Cannot move to the next room: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
}

#else
//programmer defined exceptions handling
void GameSetUp::move(std::string direction) {
    try {
        Room* nextRoomPtr = currentRoom->getNextRoom(direction);
        if (nextRoomPtr == nullptr) {
            throw invalidRoomMoveException();
        }
        if (currentRoom->isEnemyInRoom) {
            throw UndefeatedEnemyInRoomException();
        }
        currentRoom = nextRoomPtr;
        roomLogger.log(*currentRoom);
    } catch (const invalidRoomMoveException& e) {
        std::cerr << "Invalid room move: " << e.what() << std::endl;
    } catch (const UndefeatedEnemyInRoomException& e) {
        std::cerr << "Cannot move to the next room: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
}

#endif



void GameSetUp::tryKillEnemy(){
    getCurrentRoom()->removeEnemyFromRoom();
    getInventory()->removeFromInventory(*getCurrentItem());
    setCurrentItem(Item ());
}





}
