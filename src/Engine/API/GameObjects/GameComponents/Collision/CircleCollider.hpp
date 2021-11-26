//
// Created by MDstu on 26/11/2021.
//

#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
    public:
        CircleCollider(double radius, bool active);
        double radius;
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
