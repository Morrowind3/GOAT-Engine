#ifndef GOAT_ENGINE_BOXCOLLIDER_HPP
#define GOAT_ENGINE_BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class BoxCollider : public Collider {
        //Vrees niet, dit moet hacky omdat in c++ de superconstructor niet in de body kan.
    public: BoxCollider(double width, double height, bool isSensor, bool active)
                : BoxCollider(isSensor ? BoxCollider{true, width, height, active} : BoxCollider{width, height, active}){}
    private:
        BoxCollider(double width, double height, bool active);
        BoxCollider(bool dummy, double width, double height, bool active);
    };
}


#endif //GOAT_ENGINE_BOXCOLLIDER_HPP
