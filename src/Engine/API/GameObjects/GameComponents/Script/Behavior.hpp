#ifndef GOAT_ENGINE_BEHAVIOR_HPP
#define GOAT_ENGINE_BEHAVIOR_HPP

#include "../GameComponent.hpp"
#include "Script.hpp"
#include "../../../../../Libraries/Tessil/ordered_map.hpp"
#include <map>
#include <memory>

namespace Engine {
    struct Behavior : public GameComponent {
        explicit Behavior(bool active);
        tsl::ordered_map<std::string,std::shared_ptr<Script>> scripts{};
        void onStart();
        void onUpdate(double deltaTime);
        void onExternalEvent();
        void onDestroy();
        // Collisions
        void onTriggerEnter2D(GameObject& other);
        void onTriggerStay2D(GameObject& other);
        void onTriggerExit2D(GameObject& other);
    };
}

#endif //GOAT_ENGINE_BEHAVIOR_HPP
