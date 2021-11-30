#ifndef GOAT_ENGINE_BOXCOLLIDER_HPP
#define GOAT_ENGINE_BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace Engine {
    class BoxCollider : public Collider {
        public: BoxCollider(double width, double height, bool active);
        public: BoxCollider(double width, double height, bool isSensor, bool active); //TODO: Hacky manier.

    };
}


#endif //GOAT_ENGINE_BOXCOLLIDER_HPP
