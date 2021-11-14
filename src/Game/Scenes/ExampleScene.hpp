#pragma once

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/Goat.hpp"

class ExampleScene : public Scene {
    public:
        ExampleScene() : Scene("Example Scene") {
            _gameObjects.push_back(goat);
        }
        ~ExampleScene() {
            delete goat;
        }
    private:
        GameObject* goat = new Goat{Transform{Point{0.0, 0.0}, 0, 1.0, 1.0, Engine::FLIP_VERTICAL}};;
};