#ifndef GOAT_ENGINE_RECTANGLE_HPP
#define GOAT_ENGINE_RECTANGLE_HPP

#include "Point.hpp"

struct Rectangle {
    Rectangle(Point topLeft, double width, double height);
    Point topLeft;
    double width, height;
};

#endif //GOAT_ENGINE_RECTANGLE_HPP
