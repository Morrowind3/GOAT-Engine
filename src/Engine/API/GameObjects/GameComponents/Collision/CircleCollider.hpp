#ifndef GOAT_ENGINE_CIRCLECOLLIDER_HPP
#define GOAT_ENGINE_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Engine{
    class CircleCollider : public Collider {
    public: CircleCollider(double radius, bool isSensor, bool active)
                : CircleCollider(isSensor ? CircleCollider{true, radius, active} : CircleCollider{radius, active}){};
    private:
        CircleCollider(double radius, bool active);
        CircleCollider(bool dummy, double radius, bool active);
    };
}


#endif //GOAT_ENGINE_CIRCLECOLLIDER_HPP
