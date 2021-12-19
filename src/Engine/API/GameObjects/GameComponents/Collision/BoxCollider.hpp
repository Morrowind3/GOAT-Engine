#ifndef GOAT_ENGINE_BOXCOLLIDER_HPP
#define GOAT_ENGINE_BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class BoxCollider : public Collider {
        //Vrees niet, dit moet hacky omdat in c++ de superconstructor niet in de body kan.
    public: BoxCollider(double width, double height, double friction, double  bounciness, double offSetX, double offSetY, bool isSensor, bool active)
                : BoxCollider(isSensor ? BoxCollider{true, width, height,friction, bounciness, offSetX,offSetY, active} : BoxCollider{width, height, friction,bounciness, offSetX, offSetY, active}){}
    private:
        BoxCollider(double width, double height, double friction, double bounciness, double offSetX, double offSetY, bool active);
        BoxCollider(bool dummy, double width, double height, double friction, double bounciness, double offSetX, double offSetY, bool active);
    };
}


#endif //GOAT_ENGINE_BOXCOLLIDER_HPP
