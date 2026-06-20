#include "iostream"
#include "ElevatorController.h"

using namespace std;

int main() {

    std::cout << "-----------------------------------------\n";
    std::cout << "   Elevator System Simulator (SCAN)\n";
    std::cout << "-----------------------------------------\n\n";

    ElevatorController controller;

    std::cout << "[Simulation Start] Elevator at floor 0 (lobby)\n\n";

    int n;
    cout << "Enter number of floors you wanna go: ";
    cin >> n;
    cout << "Enter floors (space separated): ";
    for (int i = 0; i < n; i++) {
        int floor;
        cin >> floor;
        controller.addRequest(floor);
    }

    controller.printSystemStatus();
    cout << "\n--- Processing requests (SCAN algorithm) ---\n";
    int count = 0;
    while (controller.processNextRequest()) {
        count++;
        controller.printSystemStatus();
    }

    controller.processNextRequest();

    cout << "\n----------------------------------------------\n";
    cout << "   Simulation Complete\n";
    cout << "   Total floors served: " << count + 1 << "\n";
    cout << "----------------------------------------------\n";


    return 0;
}