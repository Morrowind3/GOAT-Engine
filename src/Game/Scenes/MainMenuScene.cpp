#include "MainMenuScene.hpp"
#include "../GameObjects/Meta/MainMenu.hpp"

MainMenuScene::MainMenuScene(SceneManager& manager): Scene(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<MainMenu>(manager,
        Transform{ Point{0,0}, 999},
    true));
}
