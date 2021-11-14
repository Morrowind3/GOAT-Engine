#pragma once

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/Goat.hpp"

using namespace Engine;

class ExampleScene : public Scene {
    public:
        ExampleScene() : Scene("Example Scene") {
            gameObjects.push_back(goat);
        }
        ~ExampleScene() {
            delete goat;
        }
    private:
        GameObject* goat = new Goat{Transform{Point{0.0, 0.0}, 0, 1.0, 1.0, FLIP::FLIP_VERTICAL}};;
};