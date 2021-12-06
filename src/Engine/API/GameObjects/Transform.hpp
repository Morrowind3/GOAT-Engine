#ifndef GOAT_ENGINE_TRANSFORM_HPP
#define GOAT_ENGINE_TRANSFORM_HPP

#include "Point.hpp"
#include "SDL.h"

namespace Engine {

    enum class FLIP {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL
    };

    struct Transform {
        // TODO: During refactor, add layer group inside constructor
        explicit Transform(Point position, unsigned int layerGroup = 0, double rotation = 0.0, double scaleWidth = 1.0,
                           double scaleHeight = 1.0, FLIP flip = FLIP::FLIP_NONE, unsigned int layer = 0);
        Point position;
        unsigned int layerGroup, layer;
        double rotation, scaleWidth, scaleHeight;
        FLIP flip;
        bool visible = true;
    };

}

#endif //GOAT_ENGINE_TRANSFORM_HPP
