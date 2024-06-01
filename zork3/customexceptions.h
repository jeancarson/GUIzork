#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <exception>

class invalidRoomMoveException: public std::exception
{
public:
    const char* what() const noexcept override;

};


class myNullPointerException: public std::exception
{
public:
    const char* what() const noexcept override;

};


class UndefeatedEnemyInRoomException: public std::exception
{
public:
    const char* what() const noexcept override;

};


#endif // CUSTOMEXCEPTIONS_H
