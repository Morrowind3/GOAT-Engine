#ifndef GOAT_ENGINE_BEHAVIOR_HPP
#define GOAT_ENGINE_BEHAVIOR_HPP

#include "../GameComponent.hpp"
#include "Script.hpp"
#include <vector>
#include <memory>

namespace Engine {
    struct Behavior : public GameComponent {
        explicit Behavior(bool active);
        std::vector<std::shared_ptr<Script>> scripts;
        void OnStart();
        void OnUpdate(double deltaTime);
        void OnExternalEvent();
        void OnDestroy();
        // TODO: Collisions
    };
}

#endif //GOAT_ENGINE_BEHAVIOR_HPP
