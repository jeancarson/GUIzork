#include "gamesetup.h"
#include <iostream>


GameSetUp::GameSetUp() {
    cout<<"SETTING UP"<<endl;
    timerWidget = new Timer();
    this-> inventory = new inventoryBackEnd();
    createRoomsAndItems();
    currentItem = new Item();
}

// }
// GameSetUp::~GameSetUp() {
//     delete currentItem;
// }

//TODO I think these paths will have to not be absolute eventually for portability

void GameSetUp::createRoomsAndItems()  {
    Room *frontDoor, *foyer, *insideLift;
    frontDoor = (new Room("Front Door"));
    frontDoor->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/conor.jpg");

    foyer = (new Room("You go through the front door. \nYou see a set of stairs and a lift"));
    foyer->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/frontDoorGeneric.jpg");

    insideLift = (new Room("You have entered the lift. North is first floor, west is second floor"));
    insideLift->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/taylor.jpg");
    cout<<"Rooms are made"<<endl;

    Item *keycard = new Item();
    Item *umbrella = new Item();
    Item *lunchbox = new Item();
    Item *bat = new Item();
    keycard->setNameAndPathToImage("keycard", "C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png");

    umbrella->setNameAndPathToImage("umbrella","C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/umbrella.png" );

    lunchbox->setNameAndPathToImage("lunchbox","C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/lunchbox.png" );
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

    //problem 3 something with coordinates
    frontDoor->setCoordinates(100, 100, 0);
    foyer -> setCoordinates(150, 150, 0);
    insideLift -> setCoordinates(150, 150, 1);
    cout<<"coordinates set"<<endl;



    Enemy *LockedDoor = new Enemy("Locked Door", *keycard,"C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png", 400, 300);
    Enemy *Mia = new Enemy("Mia", *umbrella,"C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png", 200, 500);
    Enemy *Ruan = new Enemy("Ruan", *bat, "C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png",400, 700);

    frontDoor->setEnemyInRoom(*LockedDoor);
    insideLift->setEnemyInRoom(*Mia);


    this->currentRoom = frontDoor;
    cout<<currentRoom->getDescription();

}



//need a set up UI function which assigns the background image to the next room
Room* GameSetUp::getCurrentRoom() {
    return currentRoom;
}

Item* GameSetUp::getCurrentItem(){
    return currentItem;
}

void GameSetUp::setCurrentItem(Item item){
    *currentItem = item;
    cout<< "Current item is : " + getCurrentItem()->getName() <<endl;
}


void GameSetUp::move(string direction) {
    Room* nextRoomPtr = currentRoom->getNextRoom(direction);
    if (nextRoomPtr != nullptr && !(currentRoom->isEnemyInRoom)) {
        currentRoom = nextRoomPtr;
        cout << "Moved" << endl;
        cout << currentRoom->getDescription() << endl;
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


