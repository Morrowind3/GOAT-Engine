//
// Created by Morrowind3 on 27/11/2021.
//

#include "DefeatScene.hpp"
#include "../Keys.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"
#include "../GameObjects/Meta/EtappeEnd/DefeatBackground.hpp"

DefeatScene::DefeatScene(SceneManager& manager) : Scene(Keys::DEFEAT_SCREEN) {
    gameObjects.emplace_back(std::make_shared<DefeatBackground>(Transform{Point{0, -50}, 1, 0, 1, 1}, true));

}
