#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
    public: CircleCollider(double radius, double offSetX, double offSetY, double friction, double bounciness, bool isSensor, bool active)
                : CircleCollider(isSensor ? CircleCollider{true, radius, active, offSetX, offSetY, friction, bounciness} : CircleCollider{radius, active, offSetX, offSetY, friction, bounciness}){};
    private:
        CircleCollider(double radius, bool active, double offSetX, double offSetY,double friction ,double bounciness);
        CircleCollider(bool dummy, double radius, bool active, double offSetX, double offSetY, double friction, double bounciness);
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
