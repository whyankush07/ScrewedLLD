#include "Elevator.h"
using namespace std;

void Elevator::moveOneFloor() {
    if (currentDirection == Direction::UP) {
        currentFloor++;
    } else if (currentDirection == Direction::DOWN) {
        currentFloor--;
    }
};

void Elevator::requestFloor(int floor) {
    if (floor < 0) {
        cout << "[Elevator] Invalid floor: " << floor << "\n";
        return;
    }

    if (floor == currentFloor) {
        cout << "[Elevator] Already at floor: "<< floor << "\n";
        door.open();
        return;
    }

    door.close();

    if (floor > currentFloor) {
        currentDirection = Direction::UP;
    } else {
        currentDirection = Direction::DOWN;
    }

    cout << "[Elevator] Moving"
         << (currentDirection == Direction::UP ? "UP" : "Down")
         << " to floor " << floor << ".\n";

    while (currentFloor != floor) {
        moveOneFloor();
    }

    currentDirection = Direction::IDLE;
    cout << "[Elevator] Arrived at floor " << floor << ".\n";
    door.open();
};

void Elevator::printStatus() const {
    cout << "  [Elevator Status] Floor: " << currentFloor 
              << "  | Direction: ";
    
    if (currentDirection == Direction::UP) {
        cout << "UP";
    } else if (currentDirection == Direction::DOWN) {
        cout << "DOWN";
    } else {
        cout << "IDLE";
    }
    
    cout << " | Door: " << (isDoorOpen() ? "OPEN" : "CLOSED") << "\n";
}