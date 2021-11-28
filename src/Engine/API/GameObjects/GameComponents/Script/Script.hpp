#ifndef GOAT_ENGINE_SCRIPT_HPP
#define GOAT_ENGINE_SCRIPT_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    class GameObject;
    struct Script : public GameComponent {
        explicit Script(bool active);
        virtual void onStart();
        virtual void onUpdate(double deltaTime);
        virtual void onExternalEvent();
        virtual void onDestroy();
        // Collisions
        virtual void onTriggerEnter2D(GameObject& other);
        virtual void onTriggerStay2D(GameObject& other);
        virtual void onTriggerExit2D(GameObject& other);
    };
}

#endif //GOAT_ENGINE_SCRIPT_HPP
