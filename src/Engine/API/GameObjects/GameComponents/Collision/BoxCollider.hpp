#ifndef GOAT_ENGINE_BOXCOLLIDER_HPP
#define GOAT_ENGINE_BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class BoxCollider : public Collider {
        //Vrees niet, dit moet hacky omdat in c++ de superconstructor niet in de body kan.
    public: BoxCollider(double width, double height, double friction, bool isSensor, bool active)
                : BoxCollider(isSensor ? BoxCollider{true, width, height,friction, active} : BoxCollider{width, height, friction, active}){}
    private:
        BoxCollider(double width, double height, double friction, bool active);
        BoxCollider(bool dummy, double width, double height, double friction, bool active);
    };
}


#endif //GOAT_ENGINE_BOXCOLLIDER_HPP
