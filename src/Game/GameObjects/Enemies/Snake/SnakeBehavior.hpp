#ifndef GOAT_ENGINE_SNAKEBEHAVIOR_HPP
#define GOAT_ENGINE_SNAKEBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "./Snake.hpp."

using namespace Engine;

class SnakeBehavior : public Behavior {
public:
    SnakeBehavior(Snake& snake, bool active);
};


#endif //GOAT_ENGINE_SNAKEBEHAVIOR_HPP
