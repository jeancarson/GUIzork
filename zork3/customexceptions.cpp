#include "customexceptions.h"
//programmer defined exceptions
//noexcept - garuntee that funtion will not throw an exception
const char* invalidRoomMoveException::what() const noexcept {
    return "Attempted to move in a direction where there is no exit.";
}


const char* myNullPointerException::what() const noexcept {
    return "Attempted to access a null pointer.";
}


const char* UndefeatedEnemyInRoomException::what() const noexcept {
    return "Attempted to exit the room when there is still an undefeated enemy present";
}
