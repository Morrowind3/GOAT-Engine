#ifndef GOAT_ENGINE_SCRIPT_SNAKE_HPP
#define GOAT_ENGINE_SCRIPT_SNAKE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Snake.hpp"

using namespace Engine;

class Script_Snake : public Script {
    public:
        Script_Snake(Object_Snake& snake, bool active) : Script(active), _snake(snake) {};
        void onTriggerEnter2D(GameObject &other) override;
        void onUpdate(double deltaTime) override;
    private:
        // Variables
        Object_Snake& _snake;
        std::shared_ptr<Behavior> _paralyzedObject;
        double _paralyzedTimerInMs {0};
        // Constants
        const float PUSH_FORCE{100000};
        const unsigned short PARALYZE_DURATION_IN_MS{1600};
};


#endif //GOAT_ENGINE_SCRIPT_SNAKE_HPP
