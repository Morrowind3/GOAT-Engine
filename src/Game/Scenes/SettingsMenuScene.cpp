#include "SettingsMenuScene.hpp"
#include "../Keys.hpp"
#include "../GameObjects/Utils/FpsMeter/FpsMeter.hpp"

SettingsMenuScene::SettingsMenuScene(SceneManager& manager) : Scene(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}