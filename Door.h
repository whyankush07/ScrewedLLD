#pragma once
#include "iostream"
#include "Direction.h"

using namespace std;

class Door{
private:
    DoorState state;

public:
    Door() : state(DoorState::CLOSED) {};

    void open() {
        if (state == DoorState::OPEN) {
            cout << "[Door] Already Open\n";
            return;
        }
        state = DoorState::OPEN;
        cout << "[Door] Opening Doors...\n";
    }

    void close() {
        if (state == DoorState::CLOSED) {
            cout << "[Door] Already Closed\n";
        }
        state = DoorState::CLOSED;
        cout << "[Door] Closing Doors...\n";
    }

    bool isOpen() const {
        return state == DoorState::OPEN;
    }
};