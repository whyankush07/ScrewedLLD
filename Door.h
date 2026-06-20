#pragma once
#include "iostream"
#include "Direction.h"

using namespace std;

class Door{
private:
    DoorState state;

public:
    Door() : state(DoorState::CLOSED) {};

    void open();

    void close();

    bool isOpen() const {
        return state == DoorState::OPEN;
    }
};