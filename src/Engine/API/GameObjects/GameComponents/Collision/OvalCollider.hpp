//
// Created by MDstu on 07/12/2021.
//

#ifndef GOAT_ENGINE_OVALCOLLIDER_HPP
#define GOAT_ENGINE_OVALCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class OvalCollider: public Collider {
    public:
        OvalCollider(double radius, double offSetX, double offSetY, bool active);

    };
}


#endif //GOAT_ENGINE_OVALCOLLIDER_HPP
