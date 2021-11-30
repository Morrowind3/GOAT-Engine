#include "Rectangle.hpp"

using namespace Engine;

Rectangle::Rectangle(Point topLeft, double width, double height):
        topLeft{topLeft}, width{width}, height{height} {
}

bool Rectangle::intersects(Point point) const {
    //     Inside Left X           Inside Right X                  Inside left Y           Inside right Y
    return point.x >= topLeft.x && point.x <= topLeft.x + width && point.y >= topLeft.y && point.y <= topLeft.y + height;
}
