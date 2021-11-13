#pragma once

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/Goat.hpp"

static std::vector<GameObject> EXAMPLE_GAME_COMPONENTS {
    Goat { Transform { Point { 200.0, 200.0 } } }
};

class ExampleScene : public Scene {
public:
    ExampleScene() : Scene("Example Scene") {
        _gameObjects = EXAMPLE_GAME_COMPONENTS;
    }
};