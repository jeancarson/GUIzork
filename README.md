github repo: https://github.com/jeancarson/GUIzork.git

*****
*****
**GAME INSTRUCTIONS**

You have three minutes to enter the ISE building, find a pink lunchbox, add it to your inventory and get back out the front door.
Along the way there will be 'enemies', each which can be defeated by adding the unusual item on screen to the inventory, selecting it (it will be yellow), then clicking on the enemy. The enemy disapears and you can now move. You can click on any character at any time to see what they have to say.
Moves in valid directions are shown in red, invalid are greyed out.
You can view the map by clicking the central map button. There is a red dot on the map screen which shows where you currently are.

*****

**CHEAT CODES**
* After start, click on green keycard to add to invenetory. Click again to select, then click on security guard.
* Execute the following moves: NORTH, WEST, NORTH, WEST
* Click on the umbrella to pick up, again to select and then on the enemy (MIA)
* Execute the following commands to get to the forest room: NORTH, NORTH, SOUTH
* Click on the pink lunchbox to pick it up
* Execute the following comands: WEST, EAST
* Click on the fish to pick it up, again in inventory to select, and then on the enemy (RUAN)
* Execute the following commands: SOUTH, SOUTH, EAST, SOUTH, SOUTH, SOUTH to win

*****
*****

**REQUIREMENTS**


* **Virtual functions**:                                    talk() function in the abstract Character class

* **template classes**:                                     Logger class -> can work with either Rooms or Items 

* **Multiple inheritance**:                                 CuriousCharacter and ThreateningCharacter inherit from both Character and Enemy

* **namespaces**:                                           GameSetUp namespace, as well as std namespace used throughout

* **Programmer defined exceptions**:                        Demonstrated in the gameSetUp->move() function, exceptions if trying to go in a direction without exit, or move when an enemy is present

* **Unions**:                                               Items can hold additional information to distiguish objects with the same name. Either colour (string) or price(int), not both

* **Operator overloading**:                                 == operator for Rooms and Items

* **Abstract classes**:                                    Character class is abstract, due to the presence of a virtual function

* **Copy constructors (deep , shallow copy)**:             Implemented for Rooms and Items

* **Bit structures**:                                      2 bit fields for specialised flags, one to indicate if the game is over and another to indicate if a certain amount of time has elapsed (time for a character to appear)

* **Advanced pre-processor directives**:                   A special debug version of the gameSetUp->move() method with more output messages, only declared and defined if in debug mode. Demonstration purposes only

* **C++ Object Construction Sequence**:                    Demonstrated by printing to the console messages from Enemy, Character and Curious/ThreateningCharacter constructors, showing the order in which they are constructed

* **Initializer List**:                                    Used in several places - example: MainGameWindow.cpp

* **C++ References**:                                      Used everywhere - example: InventoryBackEnd.cpp

* **Pointers**:                                            Used everywhere - example: Room.cpp

* **Inheritance**:                                         AnxiousCharacter inherits from Character

* **Destructors**:                                         Every class

* **Memory management**:                                   Using destructors to delete all dynamically allocated memory once game is over. Exiting the application correctly

* **Header files (inclusion guards)**:                     Used everywhere

* **Arrays and pointers**:                                 Room class has an array of pointers to store exits

* **Friendship**:                                          MainGameWindow and Guide classes can access the timeLeft variable of the timer to display the ingame clock

* **Global variables**:                                    Logger instances

* **Private, Public, Protected**:                          Character has a protected string PathToImage, which subclasses can access
