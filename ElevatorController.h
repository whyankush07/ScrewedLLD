#pragma once
#include "Elevator.h"
#include "set"

class ElevatorController {
private:
    Elevator elevator;
    Direction lastDirection;
    std::set<int> pendingRequests;

    int getNextFloor();

public:
    ElevatorController() : lastDirection(Direction::UP) {};

    void addRequest(int floor);

    bool processNextRequest();

    int getPendingRequestSize() const { return pendingRequests.size(); }
    void printSystemStatus() const;
};