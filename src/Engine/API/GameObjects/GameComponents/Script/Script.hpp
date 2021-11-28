#ifndef GOAT_ENGINE_SCRIPT_HPP
#define GOAT_ENGINE_SCRIPT_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    class GameObject;
    struct Script : public GameComponent {
        explicit Script(bool active);
        virtual void OnStart();
        virtual void OnUpdate(double deltaTime);
        virtual void OnExternalEvent();
        virtual void OnDestroy();
        // Collisions
        virtual void OnTriggerEnter2D(GameObject& other);
        virtual void OnTriggerStay2D(GameObject& other);
        virtual void OnTriggerExit2D(GameObject& other);
    };
}

#endif //GOAT_ENGINE_SCRIPT_HPP
