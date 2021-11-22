//
// Created by MDstu on 22/11/2021.
//

#ifndef GOAT_ENGINE_BOXCOLLIDER_HPP
#define GOAT_ENGINE_BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class BoxCollider : public Collider {
    public:
        BoxCollider(double width, double height, bool active);

        double width;
        double height;
    };
}


#endif //GOAT_ENGINE_BOXCOLLIDER_HPP
