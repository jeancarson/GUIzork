#include "gamesetup.h"
#include <iostream>


GameSetUp::GameSetUp() {
    cout<<"SETTING UP"<<endl;
    timerWidget = new Timer();
    inventory = new inventoryBackEnd();

}

//TODO I think these paths will have to not be absolute eventually for portability

void GameSetUp::createRooms()  {
    Room *frontDoor, *foyer, *insideLift;
    cout<<"START OF CREAT ROOMS METHOD" <<endl;
    frontDoor = (new Room("You are at the front door, you must swipe your card"));
    cout <<"ROOM 1 MADE"<<endl;
    frontDoor->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/conor.jpg");
    cout<<"PATH TO IMAGE 1 SET"<<endl;
    foyer = (new Room("You go through the front door. \nYou see a set of stairs and a lift"));
    foyer->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/frontDoorGeneric.jpg");
    cout << "PATH TO IMAGE 2 SET" <<endl;
    insideLift = (new Room("You have entered the lift. North is first floor, west is second floor"));
    insideLift->setPathToImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/taylor.jpg");
    cout << "PATH TO IMAGE 3 SET" <<endl;


//             (N, E, S, W)
    frontDoor->setExits(foyer, NULL, NULL, NULL);
    foyer->setExits(NULL, NULL, frontDoor, insideLift);
    insideLift->setExits(NULL, foyer, NULL, NULL);

    //problem 3 something with coordinates
    frontDoor->setCoordinates(100, 100, 0);
    foyer -> setCoordinates(150, 150, 0);
    insideLift -> setCoordinates(150, 150, 1);

    this->currentRoom = frontDoor;
    cout<<currentRoom->getDescription();

}

//need a set up UI function which assigns the background image to the next room
Room* GameSetUp::getCurrentRoom() {
    return currentRoom;
}
void GameSetUp::move(string direction) {
    Room* nextRoomPtr = currentRoom->getNextRoom(direction);
    if (nextRoomPtr != nullptr) {
        currentRoom = nextRoomPtr; // Update current room to the next room
        cout << "Moved" << endl;
        cout << currentRoom->getDescription() << endl;
    } else {
        cout << "You cannot move in that direction." << endl;
    }
}

// void GameSetUp::initialiseTimerWidget() {
//     timerWidget = new Timer();
//     timerWidget->show();
// }


Timer* GameSetUp::getTimer(){
    return timerWidget;
}

vector<Item> GameSetUp:: getItemsBackEnd(){
    return inventory->getInventory();
}



