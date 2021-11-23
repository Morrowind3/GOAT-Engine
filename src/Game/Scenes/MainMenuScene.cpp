#include "MainMenuScene.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"

MainMenuScene::MainMenuScene(SceneManager& manager) : Scene(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<Background>(
            manager, Transform{Point{0, 0}, 0, 0, 1.4, 1.4}, true));
}
