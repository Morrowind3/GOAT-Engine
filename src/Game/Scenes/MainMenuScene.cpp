#include "MainMenuScene.hpp"
#include "../GameObjects/Meta/MainMenu/Background.hpp"
#include "../GameObjects/Meta/MainMenu/ExitButton.hpp"
#include "../GameObjects/Meta/MainMenu/PlayButton.hpp"
#include "../GameObjects/Meta/MainMenu/ScoreboardButton.hpp"
#include "../GameObjects/Meta/MainMenu/SettingsButton.hpp"
#include "../GameObjects/Meta/MainMenu/DebugButton.hpp"
#include "../GameObjects/Enemies/Hawk.hpp"
#include "../GameObjects/Meta/Hud/FpsDisplay.hpp"
#include "../Keys.hpp"

MainMenuScene::MainMenuScene(SceneManager& manager) : Scene(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<FpsDisplay>(true));
    gameObjects.emplace_back(std::make_shared<Background>(
            manager, Transform{Point{0, -50}, 1, 0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<ExitButton>(
            manager, Transform{Point{20, 40}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<SettingsButton>(
            manager, Transform{Point{1710, 40}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<PlayButton>(
            manager, Transform{Point{800, 350}, 100, 0, 5, 5}, true));
    gameObjects.emplace_back(std::make_shared<ScoreboardButton>(
            manager, Transform{Point{800, 530}, 100, 0, 5, 5}, true));
    gameObjects.emplace_back(std::make_shared<DebugButton>(
            manager, Transform{Point{825, 800}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<Hawk>(
            Transform{Point{200, 300}, 2, 0, 4, 4}, true));
}
