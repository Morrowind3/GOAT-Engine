//
// Created by Morrowind3 on 27/11/2021.
//

#include "VictoryScene.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"
#include "../Keys.hpp"
#include "../GameObjects/Meta/EtappeEnd/VictoryBackground.hpp"
#include "../GameObjects/Meta/EtappeEnd/NextEtappeButton.hpp"
#include "../GameObjects/Meta/EtappeEnd/SelectEtappeButton.hpp"

VictoryScene::VictoryScene(SceneManager& manager) : Scene(Keys::VICTORY_SCREEN) {
    gameObjects.emplace_back(std::make_shared<VictoryBackground>(Transform{Point{0, 0}, 1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<SelectEtappeButton>(
            manager, Transform{Point{560, 850}, 100, 0, 6, 5}, true));
    gameObjects.emplace_back(std::make_shared<NextEtappeButton>(
            manager, Transform{Point{970, 850}, 100, 0, 6, 5}, true));

}