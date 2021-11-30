#ifndef GOAT_ENGINE_RECTANGLE_HPP
#define GOAT_ENGINE_RECTANGLE_HPP

#include "Point.hpp"

namespace Engine {
    struct Rectangle {
        Rectangle(Point topLeft, double width, double height);
        Point topLeft;
        double width, height;
        [[nodiscard]] bool intersects(Point point) const;
    };
}


#endif //GOAT_ENGINE_RECTANGLE_HPP
