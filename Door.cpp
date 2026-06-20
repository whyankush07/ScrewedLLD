#include "iostream"
#include "Door.h"

void Door::open() {
    if (state == DoorState::OPEN) {
        cout << "[Door] Already Open\n";
        return;
    }
    state = DoorState::OPEN;
    cout << "[Door] Opening Doors...\n";
}

void Door::close() {
    if (state == DoorState::CLOSED) {
        cout << "[Door] Already Closed\n";
    }
    state = DoorState::CLOSED;
    cout << "[Door] Closing Doors...\n";
}