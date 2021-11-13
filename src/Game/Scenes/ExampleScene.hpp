#pragma once

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/Goat.hpp"

static std::vector<GameObject> EXAMPLE_GAME_COMPONENTS{
    Goat{Transform{Point{0.0, 0.0}, 0, 1.0, 1.0, Engine::FLIP_VERTICAL}}
};

class ExampleScene : public Scene {
public:
    ExampleScene() : Scene("Example Scene") {
        _gameObjects = EXAMPLE_GAME_COMPONENTS;
    }
};