#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "room.h"
#include "item.h"

//Template classes
template<typename T>
class Logger {
public:
    Logger(const std::string& filename) : filename(filename) {}
    void log(const T& thing);
private:
    std::string filename = "C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Logs.txt";

};


// Declaration of function template specialization for Item
template<>
void Logger<Item>::log(const Item& item);

// Declaration of function template specialization for Room
//use of references
template<>
void Logger<Room>::log(const Room& room);

template<>
void Logger<Enemy>::log(const Enemy& enemy);
//GLOBAL variables
extern Logger<Item> itemLogger;
extern Logger<Room> roomLogger;
extern Logger<Enemy> enemyLogger;
#endif // LOGGER_H
