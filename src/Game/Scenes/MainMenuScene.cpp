#include "MainMenuScene.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"
#include "../GameObjects/Meta/MainMenu/ExitButton.hpp"
#include "../GameObjects/Meta/MainMenu/PlayButton.hpp"
#include "../GameObjects/Enemies/Hawk.hpp"

MainMenuScene::MainMenuScene(SceneManager& manager) : Scene(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<Background>(
            manager, Transform{Point{0, 0}, 1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<ExitButton>(
            manager, Transform{Point{20, 20}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<PlayButton>(
            manager, Transform{Point{800, 400}, 100, 0, 5, 5}, true));
    gameObjects.emplace_back(std::make_shared<Hawk>(
            Transform{Point{200, 300}, 2, 0, 4, 4}, true));
}
