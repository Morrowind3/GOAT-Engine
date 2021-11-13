#pragma once

#include "Point.hpp"

struct Transform {
    Point position;
    double rotation, width, height;

    Transform(Point position, double rotation, double width, double height);
    explicit Transform(Point position);
};