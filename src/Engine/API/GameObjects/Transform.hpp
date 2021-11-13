#pragma once

#include "Point.hpp"

namespace Engine {
    struct Transform {
        Transform(Point position, double rotation, double width, double height);
        explicit Transform(Point position);
        Point position;
        double rotation, width, height;
    };
}
