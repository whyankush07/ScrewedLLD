#!/bin/bash

# Compile the project
echo "Compiling the Elevator project..."
g++ -std=c++17 -Wall -o elevator main.cpp Elevator.cpp Door.cpp ElevatorController.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running..."
    echo "-----------------------------------------"
    ./elevator.exe
else
    echo "Compilation failed!"
    exit 1
fi
