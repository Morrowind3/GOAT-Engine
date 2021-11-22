//
// Created by MDstu on 22/11/2021.
//

#ifndef GOAT_ENGINE_COLLIDER_HPP
#define GOAT_ENGINE_COLLIDER_HPP

#include "../GameComponent.hpp"

namespace Engine {
    class Collider : public GameComponent {
    public:
        Collider(bool active);
    };
}

#endif //GOAT_ENGINE_COLLIDER_HPP
