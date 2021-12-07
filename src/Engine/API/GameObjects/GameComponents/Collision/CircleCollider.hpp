#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
    public: CircleCollider(double radius, double offSetX, double offSetY, bool isSensor, bool active)
                : CircleCollider(isSensor ? CircleCollider{true, radius, active, offSetX, offSetY} : CircleCollider{radius, active, offSetX, offSetY}){};
    private:
        CircleCollider(double radius, bool active, double offSetX, double offSetY);
        CircleCollider(bool dummy, double radius, bool active, double offSetX, double offSetY);
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
