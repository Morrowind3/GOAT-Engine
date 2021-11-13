#pragma once

#include "../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"

using namespace Engine;

class Goat : public GameObject {
    public:
        explicit Goat(Transform transform) : GameObject(transform, Sprite{"Goat.png", true}, true) {}
};