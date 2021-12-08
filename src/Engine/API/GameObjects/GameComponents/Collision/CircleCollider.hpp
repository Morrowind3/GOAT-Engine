#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
    public: CircleCollider(double radius, double offSetX, double offSetY, double friction, bool isSensor, bool active)
                : CircleCollider(isSensor ? CircleCollider{true, radius, active, offSetX, offSetY, friction} : CircleCollider{radius, active, offSetX, offSetY, friction}){};
    private:
        CircleCollider(double radius, bool active, double offSetX, double offSetY,double friction);
        CircleCollider(bool dummy, double radius, bool active, double offSetX, double offSetY, double friction);
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
