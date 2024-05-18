#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "room.h"
#include "item.h"

template<typename T>
class Logger {
public:
    Logger(const std::string& filename) : filename(filename) {}

    void log(const T& thing);
private:
    std::string filename; // Member variable declaration

};


// Declaration of function template specialization for Item
template<>
void Logger<Item>::log(const Item& item);

// Declaration of function template specialization for Room
template<>
void Logger<Room>::log(const Room& room);

#endif // LOGGER_H