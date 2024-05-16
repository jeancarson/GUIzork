#include "logger.h"

using namespace std;


template<>
void Logger<Item>::log(const Item& item) {
    ofstream file(filename, ios_base::app);
    if (file.is_open()) {
        time_t currentTime = time(nullptr);
        string timeString = ctime(&currentTime);
        // timeString adds a new line character at the end so remove it
        timeString.pop_back();

        file << timeString << " Current item set to " << item.getName()  << endl;
    } else {
        cerr << "Failed to open log file." << endl;
    }
}

template<>
void Logger<Room>::log(const Room& room) {
    ofstream file(filename, ios_base::app);
    if (file.is_open()) {
        time_t currentTime = time(nullptr);
        string timeString = ctime(&currentTime);
        timeString.pop_back();

        file << timeString << " - Entered into a new room: "  << room.getDescription() << std::endl;
    } else {
        cerr << "Failed to open log file." << endl;
    }
}
