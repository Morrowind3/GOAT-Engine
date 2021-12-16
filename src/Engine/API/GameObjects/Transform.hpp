#ifndef GOAT_ENGINE_TRANSFORM_HPP
#define GOAT_ENGINE_TRANSFORM_HPP

#include "Point.hpp"

namespace Engine {

    enum class FLIP {
        FLIP_NONE,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL
    };

    class RendererImpl; // Friend class link
    class Camera; // Friend class link
    struct Transform {
        explicit Transform(Point position, unsigned int layerGroup = 0, unsigned int layerInsideGroup = 0, double rotation = 0.0,
                           double scaleWidth = 1.0, double scaleHeight = 1.0, FLIP flip = FLIP::FLIP_NONE);
        Point position;
        unsigned int layerGroup, layerInsideGroup;
        double rotation, scaleWidth, scaleHeight;
        FLIP flip;
        bool visible = true;
        private:
            friend class Engine::RendererImpl;
            friend class Engine::Camera;
            bool _isParallax;
            bool _isGui;
    };

}

#endif //GOAT_ENGINE_TRANSFORM_HPP
