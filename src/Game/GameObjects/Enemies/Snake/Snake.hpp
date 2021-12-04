#ifndef GOAT_ENGINE_SNAKE_HPP
#define GOAT_ENGINE_SNAKE_HPP


#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Snake : public GameObject {
public:
    Snake(Transform transform, bool active);
};


#endif //GOAT_ENGINE_SNAKE_HPP
