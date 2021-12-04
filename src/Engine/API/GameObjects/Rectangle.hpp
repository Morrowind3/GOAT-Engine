#ifndef GOAT_ENGINE_RECTANGLE_HPP
#define GOAT_ENGINE_RECTANGLE_HPP

#include "Point.hpp"

namespace Engine {
    struct Rectangle {
        Rectangle(Point topLeft, double width, double height);
        Point topLeft;
        double width, height;
        // Reusable helper methods that are needed for most rectangle calculations
        [[nodiscard]] bool intersects(Point point) const;
        [[nodiscard]] Point widthHeightPoint() const;
        [[nodiscard]] Point topRight() const;
        [[nodiscard]] Point bottomLeft() const;
        [[nodiscard]] Point bottomRight() const;
    };
}


#endif //GOAT_ENGINE_RECTANGLE_HPP
