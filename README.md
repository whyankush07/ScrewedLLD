# Elevator Simulator 🛗

A console-based elevator system simulation written in C++17, demonstrating the **SCAN algorithm** for efficiently routing and handling floor requests.

## Features
- Simulates real-time elevator behavior (Moving, Doors Opening/Closing, Idle states).
- Handles multiple floor requests asynchronously.
- Uses the **SCAN algorithm** to minimize wait times and direction changes.
- Clean object-oriented design (`Elevator`, `ElevatorController`, `Door`).

## Getting Started

You can compile and run the project instantly using the provided shell script:

```bash
./run.sh
```

*(Alternatively, you can compile manually using `g++ -std=c++17 -Wall -o elevator main.cpp Elevator.cpp Door.cpp ElevatorController.cpp` and run `./elevator`)*

## Usage
When the simulation starts, simply enter the number of floors you want to visit and list them out. The `ElevatorController` will process the requests and simulate the elevator movement step-by-step.