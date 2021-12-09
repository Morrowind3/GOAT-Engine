#ifndef GOAT_ENGINE_BEHAVIOR_HPP
#define GOAT_ENGINE_BEHAVIOR_HPP

#include "../GameComponent.hpp"
#include "Script.hpp"
#include "../../../../../Libraries/Tessil/ordered_map.hpp"
#include <map>
#include <memory>

namespace Engine {
    class ScriptSystem; // Friend class link
    struct Behavior : public GameComponent {
        explicit Behavior(bool active);
        tsl::ordered_map<std::string,std::shared_ptr<Script>> scripts{}; // Insertion order very important so must be stored
        void onStart();
        void onUpdate(double deltaTime);
        void onExternalEvent();
        void onDestroy();
        // Collisions
        void onTriggerEnter2D(GameObject& other);
        void onTriggerStay2D(GameObject& other);
        void onTriggerExit2D(GameObject& other);
        private:
            friend class Engine::ScriptSystem;
            bool _onStartCalled {false}; // When false (behavior not yet ran), script system will run onStart and set this to true
    };
}

#endif //GOAT_ENGINE_BEHAVIOR_HPP
