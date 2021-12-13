#ifndef GOAT_ENGINE_BEHAVIOR_SNAKE_HPP
#define GOAT_ENGINE_BEHAVIOR_SNAKE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "./Object_Snake.hpp"

using namespace Engine;

class Behavior_Snake : public Behavior {
public:
    Behavior_Snake(Object_Snake& snake, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_SNAKE_HPP
