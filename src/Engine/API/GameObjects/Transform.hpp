#pragma once

#include "Point.hpp"
#include "SDL.h"

namespace Engine {
    enum FLIP {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL
    };

    struct Transform {
        explicit Transform(Point position, double rotation = 0.0, double scaleWidth = 1.0, double scaleheight = 1.0,
                           FLIP flip = FLIP_NONE);

        Point _position;
        double _rotation, _scaleWidth, _scaleheight;
        FLIP _flip;

    };
}
