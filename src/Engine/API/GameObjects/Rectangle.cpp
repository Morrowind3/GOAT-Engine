#include "Rectangle.hpp"

using namespace Engine;

Rectangle::Rectangle(Point topLeft, double width, double height):
        topLeft{topLeft}, width{width}, height{height} {
}

bool Rectangle::intersects(Point point) const {
    //     Inside Left X           Inside Right X                  Inside left Y           Inside right Y
    return point.x >= topLeft.x && point.x <= topLeft.x + width && point.y >= topLeft.y && point.y <= topLeft.y + height;
}

// TODO: There's probably a way more elegant way to do this so I'll leave this commented out until needed
//RectangleIntersection Rectangle::intersects(Rectangle rectangle) const {
//    Point topRight {topLeft}; topRight.x += width;
//    Point bottomLeft {topLeft}; bottomLeft.y += height;
//    Point bottomRight {bottomLeft}; bottomRight.x += width;
//
//    bool intersectNorthWest = rectangle.intersects(topLeft);
//    bool intersectNorthEast = rectangle.intersects(topRight);
//    bool intersectSouthWest = rectangle.intersects(bottomLeft);
//    bool intersectSouthEast = rectangle.intersects(bottomRight);
//
//    if (intersectNorthWest && intersectNorthEast && intersectSouthWest && intersectSouthEast) return RectangleIntersection::ALL;
//    if (intersectNorthWest && intersectNorthEast) return RectangleIntersection::NORTH_WEST_EAST;
//    if (intersectNorthWest && intersectSouthWest) return RectangleIntersection::NORTH_SOUTH_WEST;
//    if (intersectNorthWest && intersectSouthEast) return RectangleIntersection::NORTH_SOUTH_EAST;
//    if (intersectSouthWest && intersectSouthEast) return RectangleIntersection::SOUTH_WEST_EAST;
//    if (intersectNorthWest) return RectangleIntersection::NORTH_WEST;
//    if (intersectNorthEast) return RectangleIntersection::NORTH_EAST;
//    if (intersectSouthWest) return RectangleIntersection::SOUTH_WEST;
//    if (intersectSouthEast) return RectangleIntersection::SOUTH_EAST;
//    return RectangleIntersection::FALSE;
//}
