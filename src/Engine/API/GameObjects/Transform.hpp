#ifndef GOAT_ENGINE_TRANSFORM_HPP
#define GOAT_ENGINE_TRANSFORM_HPP

#include "Point.hpp"

namespace Engine {

    enum class FLIP {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL
    };

    struct Transform {
        explicit Transform(Point position, unsigned int layerGroup = 0, unsigned int layerInsideGroup = 0, double rotation = 0.0,
                           double scaleWidth = 1.0, double scaleHeight = 1.0, FLIP flip = FLIP::FLIP_NONE);
        Point position;
        unsigned int layerGroup, layerInsideGroup;
        double rotation, scaleWidth, scaleHeight;
        FLIP flip;
        bool visible = true;
    };

}

#endif //GOAT_ENGINE_TRANSFORM_HPP
