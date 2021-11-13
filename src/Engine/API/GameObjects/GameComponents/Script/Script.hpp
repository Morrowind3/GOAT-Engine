#ifndef GOAT_ENGINE_SCRIPT_HPP
#define GOAT_ENGINE_SCRIPT_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    struct Script : public GameComponent {
        Script(bool active);
        virtual void OnStart() = 0;
        virtual void OnUpdate(double deltaTime) = 0;
        virtual void OnDestroy() = 0;
        // TODO: Collisions
    };
}

#endif //GOAT_ENGINE_SCRIPT_HPP
