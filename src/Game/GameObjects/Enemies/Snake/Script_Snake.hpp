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
    Object_Snake& _snake;
    std::shared_ptr<Behavior> _paralyzedObject;
    int _paralyzedDuration{0};

    float PUSH_FORCE{100000};
    int PARALYZE_DURATION{100};
};


#endif //GOAT_ENGINE_SCRIPT_SNAKE_HPP
