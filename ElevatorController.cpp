#include "ElevatorController.h"
#include "iostream"
#include "algorithm"

using namespace std;

int ElevatorController::getNextFloor() {
    if (pendingRequests.empty()) {
        return elevator.getCurrentFloor();
    }

    int current = elevator.getCurrentFloor();

    auto it = pendingRequests.lower_bound(current);
    bool has_upper = (it != pendingRequests.end());
    bool has_lower = (it != pendingRequests.begin());

    if (lastDirection == Direction::UP && has_upper) {
        return *it;
    }

    if (lastDirection == Direction::DOWN && has_lower) {
        --it;
        return *it;
    }

    if (has_upper) {
        lastDirection = Direction::UP;
        return *it;
    }

    if (has_lower) {
        lastDirection = Direction::DOWN;
        --it;
        return *it;
    }

    return current;

}

void ElevatorController::addRequest(int floor) {
    if (floor < 0) {
        cout << "[Controller] Invalid floor request: " << floor << "\n";
        return;
    }

    if (pendingRequests.find(floor) != pendingRequests.end()) {
        cout << "[Controller] Floor " << floor << " already requested.\n";
        return;
    }

    pendingRequests.insert(floor);
    cout << "[Controller] Request added for floor " << floor 
              << " (pending: " << pendingRequests.size() << ")\n";
}

bool ElevatorController::processNextRequest() {
    if (pendingRequests.empty()) {
        cout << "[Controller] No pending requests. Elevator is IDLE.\n";
        return false;
    }

    int nextFloor = getNextFloor();
    cout << "\n[Controller] Processing: sending elevator to floor " << nextFloor << "\n";

    elevator.requestFloor(nextFloor);
    pendingRequests.erase(nextFloor);

    cout << "[Controller] Floor " << nextFloor << " served. "
              << "Remaining: " << pendingRequests.size() << "\n";

    return !pendingRequests.empty();
}

void ElevatorController::printSystemStatus() const {
    cout << "\n--- System Status ---\n";
    elevator.printStatus();
    cout << "Pending requests: ";
    if (pendingRequests.empty()) {
        cout << "None\n";
    } else {
        for (int floor : pendingRequests) {
            cout << floor << " ";
        }
        cout << "\n";
    }
    cout << "----------------------\n";
}