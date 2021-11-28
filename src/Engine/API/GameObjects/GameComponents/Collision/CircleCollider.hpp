#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
        public: CircleCollider(double radius, bool active);
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
