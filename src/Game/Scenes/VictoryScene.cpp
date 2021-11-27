//
// Created by Morrowind3 on 27/11/2021.
//

#include "VictoryScene.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"
#include "../Keys.hpp"
#include "../GameObjects/Meta/VictoryBackground.hpp"

VictoryScene::VictoryScene(SceneManager& manager) : Scene(Keys::VICTORY_SCREEN) {
    gameObjects.emplace_back(std::make_shared<VictoryBackground>(Transform{Point{0, -50}, 1, 0, 1, 1}, true));
}
