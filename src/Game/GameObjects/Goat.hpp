#pragma once

#include "../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Sprite.hpp"

// TODO: Research object splicing
static const std::vector<GameComponent> GOAT_COMPONENTS {
    Sprite { "Goat.png", true }
};

class Goat : public GameObject {
    public:
        explicit Goat(Transform transform) : GameObject(transform, Sprite{"Goat.png", true}, GOAT_COMPONENTS) {}
};