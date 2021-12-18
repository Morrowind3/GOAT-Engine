#ifndef GOAT_ENGINE_OVALCOLLIDER_HPP
#define GOAT_ENGINE_OVALCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class OvalCollider: public Collider {
    public:
        OvalCollider(double radius, double offSetX, double offSetY, double  friction, double bounciness, bool active);
    };
}


#endif //GOAT_ENGINE_OVALCOLLIDER_HPP
