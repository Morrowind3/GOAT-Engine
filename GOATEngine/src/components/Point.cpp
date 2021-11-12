#include "Point.hpp"

using namespace Engine;

Point::Point(float x, float y): _x{x}, _y{y} {
}

float Point::x() const {
    return _x;
}

float Point::y() const {
    return _y;
}

void Point::x(float x) {
    _x = x;
}

void Point::y(float y) {
    _y = y;
}
