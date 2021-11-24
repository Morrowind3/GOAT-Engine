#ifndef GOAT_ENGINE_RECTANGLE_HPP
#define GOAT_ENGINE_RECTANGLE_HPP

#include "Point.hpp"

namespace Engine {

    enum class RectangleIntersection {
        FALSE = 0b0000, NORTH = 0b1000, SOUTH = 0b0100, WEST = 0b0010, EAST = 0b0001, ALL = 0b1111,
        NORTH_SOUTH = 0b1100, NORTH_WEST = 0b1010, NORTH_EAST = 0b1001, SOUTH_WEST = 0b0110, SOUTH_EAST = 0b0101, WEST_EAST = 0b0011,
        NORTH_SOUTH_WEST = 0b1110, NORTH_SOUTH_EAST = 0b1101, NORTH_WEST_EAST = 0b1011, SOUTH_WEST_EAST = 0b0111,
    };

    struct Rectangle {
        Rectangle(Point topLeft, double width, double height);
        Point topLeft;
        double width, height;
        [[nodiscard]] bool intersects(Point point) const;
        //[[nodiscard]] RectangleIntersection intersects(Rectangle rectangle) const;
    };
}


#endif //GOAT_ENGINE_RECTANGLE_HPP
