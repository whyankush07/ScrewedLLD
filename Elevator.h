#include "iostream"
#include "Direction.h"
#include "Door.h"
#include "Request.h"

class Elevator {
private:
    int currentFloor;
    Direction currentDirection;
    Door door;

    void moveOneFloor();

public:
    Elevator(): currentFloor(0), currentDirection(Direction::IDLE) {};

    void requestFloor(int floor);

    int getCurrentFloor() const {
        return currentFloor;
    }

    Direction getCurrentDirection() const{
        return currentDirection;
    }

    bool isDoorOpen() const {
        return door.isOpen();
    }

    void printStatus() const;
};