#pragma once
#include "Direction.h"

struct Request
{
    int floor;
    Direction direction;

    Request(int floor, Direction direction = Direction::IDLE) : floor(floor), direction(direction) {};

    bool operator==(const Request &other) {
        return floor == other.floor;
    }
};
