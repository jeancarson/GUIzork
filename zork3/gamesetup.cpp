#include "gamesetup.h"
#include <iostream>
GameSetUp::GameSetUp() {}
// void ZorkUL::createRooms()  {
//     Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

//     a = new Room("You are at the front door, you must swipe your card");
//         a->addItem(new Item("keycard", 1, 11));
//     b = new Room("You go through the front door. \nYou see a set of stairs and a lift");
//         // b->addItem(new Item("xx", 3, 33));
//         // b->addItem(new Item("yy", 4, 44));
//     c = new Room("You have entered the lift. North is first floor, west is second floor");
//         // c->addItem(new Item("Massive item", 2, 6));
//         // c->addItem(new Item("small item",4, 6 ));
//     d = new Room("You have climbed the first flight of stairs. You can go up th esecond flight if you like");
//     e = new Room("You have climbed the second flight of stairs");
//     f = new Room("You are at the top of the landing, east or west?");
//     g = new Room("You are in the kitchen");
//     h = new Room("You are in the studio");
// 	i = new Room("i");
//     j = new Room("j");
//         j->addItem(new Item("jjJ", 1, 4));

// //             (N, E, S, W)
//     a->setExits(b, NULL, NULL, NULL);
//     b->setExits(NULL, d, a, c);
//     c->setExits(f, b, NULL, NULL);
//     d->setExits(e, NULL, f, b);
//     e->setExits(NULL, NULL, d, b);
//     f->setExits(NULL, h, c, g);
//     g->setExits(NULL, f, NULL, NULL);
//     h->setExits(NULL, NULL, f, NULL);

//         currentRoom = a;
// }


//-------------------------------------------------------------------------------




void GameSetUp::createRooms()  {
    Room *frontDoor, *foyer, *insideLift;

    frontDoor = new Room("You are at the front door, you must swipe your card");
    frontDoor->setPathToImage(":/frontDoorGeneric.jpg");
        // a->addItem(new Item("keycard", 1, 11));
    foyer = new Room("You go through the front door. \nYou see a set of stairs and a lift");
    foyer->setPathToImage(":/insideFrontDoorGeneric.jpg");
        // b->addItem(new Item("xx", 3, 33));
        // b->addItem(new Item("yy", 4, 44));
    insideLift = new Room("You have entered the lift. North is first floor, west is second floor");
    insideLift->setPathToImage(":/insideLiftGeneric.jpg");
        // c->addItem(new Item("Massive item", 2, 6));
        // c->addItem(new Item("small item",4, 6 ));
        // j->addItem(new Item("jjJ", 1, 4));

//             (N, E, S, W)
    frontDoor->setExits(foyer, NULL, NULL, NULL);
    foyer->setExits(NULL, NULL, frontDoor, insideLift);
    insideLift->setExits(NULL, foyer, NULL, NULL);


    this->currentRoom = frontDoor;
    cout<<currentRoom->getDescription();

}

//need a set up UI function which assigns the background image to the next room
Room GameSetUp:: getCurrentRoom(){
    return *currentRoom;
}

void GameSetUp::move(string direction){
    Room nextRoom = currentRoom->getNextRoom(direction);
    currentRoom = new Room(nextRoom); // Allocate memory for new room
    cout << "moved" << endl;
    cout << currentRoom->getDescription() << endl;
}


