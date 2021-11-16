//
// Created by Stijn van Loon on 16-11-2021.
//

#ifndef GOAT_ENGINE_MAINMENUSCENE_HPP
#define GOAT_ENGINE_MAINMENUSCENE_HPP

#include "../../Engine/API/Scene.hpp"
#include "../../Engine/API/Canvas.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Hud/Text.hpp"
#include <vector>

using namespace Engine;

class MainMenuScene : public Scene {
public:
    MainMenuScene() : Scene("MainMenuScene") {

        Text text {"Hallo", "", 26, {0, 255, 0}, TOP_CENTER};
        std::unique_ptr<Canvas> canvas = std::make_unique<Canvas>(Canvas{100, 100, {text}});
    }
private:
};

#endif //GOAT_ENGINE_MAINMENUSCENE_HPP
