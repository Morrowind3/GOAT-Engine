#include "Rectangle.hpp"

using namespace Engine;

Rectangle::Rectangle(Point topLeft, double width, double height):
        topLeft{topLeft}, width{width}, height{height} {
}

bool Rectangle::intersects(Point point) const {
    //     Inside Left X           Inside Right X                  Inside left Y           Inside right Y
    return point.x >= topLeft.x && point.x <= topLeft.x + width && point.y >= topLeft.y && point.y <= topLeft.y + height;
}

Point Rectangle::widthHeightPoint() const {
    return {width,height};
}

Point Rectangle::topRight() const {
    return {topLeft.x+width,topLeft.y};
}

Point Rectangle::bottomLeft() const {
    return {topLeft.x,topLeft.y+height};
}

Point Rectangle::bottomRight() const {
    return {topLeft.x+width,topLeft.y+height};
}
