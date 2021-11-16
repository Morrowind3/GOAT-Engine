#ifndef GOAT_ENGINE_SCRIPT_HPP
#define GOAT_ENGINE_SCRIPT_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    struct Script : public GameComponent {
        explicit Script(bool active);
        virtual void OnStart();
        virtual void OnUpdate(double deltaTime);
        virtual void OnDestroy();
        // TODO: Collisions
    };
}

#endif //GOAT_ENGINE_SCRIPT_HPP
