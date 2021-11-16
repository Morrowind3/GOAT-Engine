#pragma once

#include "Point.hpp"
#include "SDL.h"

namespace Engine {

    enum class FLIP {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL
    };

    struct Transform {
        explicit Transform(Point position, unsigned int layer = 0, double rotation = 0.0, double scaleWidth = 1.0,
                           double scaleHeight = 1.0, FLIP flip = FLIP::FLIP_NONE);
        Point position;
        unsigned int layer;
        double rotation, scaleWidth, scaleHeight;
        FLIP flip;
    };

}
