#include "MainMenuScene.hpp"
#include "../../GameObjects/Enemies/Hawk/Hawk.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Background.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Buttons/PlayButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Buttons/BackToSaveScreenButton.hpp"

MainMenuScene::MainMenuScene() : SceneTemplate_Menu(Keys::MAIN_MENU) {
    // Cosmetics
    gameObjects.emplace_back(std::make_shared<Background>(
            Transform{Point{0, -50}, 0, 0,0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<Hawk>(
            Transform{Point{200, 300}, LAYER::CHARACTER, 0, 0, 4, 4}, true));

    // Buttons
    gameObjects.emplace_back(std::make_shared<PlayButton>(
            Transform{Point{800, 350}, LAYER::UI, 0, 0, 5, 5}, true));
    gameObjects.emplace_back(std::make_shared<BackToSaveScreenButton>(
            Transform{Point{675, 575}, LAYER::UI, 0,0, 6, 4}, true));

    // TODO: Re-enable buttons when they do what they're supposed to do
    /*
    gameObjects.emplace_back(std::make_shared<DebugButton>(
            manager, Transform{Point{825, 800}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<SettingsButton>(
            manager, Transform{Point{1710, 40}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<ScoreboardButton>(
            manager, Transform{Point{800, 530}, 100, 0, 5, 5}, true));
    */
}
