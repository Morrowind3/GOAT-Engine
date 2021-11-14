#pragma once

#include <memory>
#include <vector>

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/Goat.hpp"

using namespace Engine;

class ExampleScene : public Scene {
    public:
        ExampleScene() : Scene("Example Scene") {
            for (int i = 0; i < 100; ++i) {
                _goats.push_back(std::make_unique<Goat>(Transform{Point{0.0,static_cast<double>(i*2)},0,1.0,1.0,FLIP::FLIP_VERTICAL}));
            }
            for (auto& goat : _goats) {
                gameObjects.emplace_back(goat.get());
            }
        }
    private:
        std::vector<std::unique_ptr<GameObject>> _goats {};
};