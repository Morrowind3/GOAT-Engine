#include "MainMenuScene.hpp"
#include "../../GameObjects/Enemies/Hawk/Hawk.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Background.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/PlayButton.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/DebugButton/DebugButton.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/ExitButton/ExitButton.hpp"
#include "../../Layers.hpp"

MainMenuScene::MainMenuScene(SceneManager& manager) : SceneTemplate_Menu(Keys::MAIN_MENU) {
    gameObjects.emplace_back(std::make_shared<Background>(
            manager, Transform{Point{0, -50}, 0, 0,0, 1, 1}, true));
    gameObjects.emplace_back(std::make_shared<PlayButton>(
            manager, Transform{Point{800, 350}, LAYER::UI, 0, 0, 5, 5}, true));
    gameObjects.emplace_back(std::make_shared<DebugButton>( // Temporary placement so it looks nicer
            manager, Transform{Point{825, 525}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<ExitButton>( // Temporary placement so it looks nicer
            manager, Transform{Point{825, 600}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<Hawk>(
            Transform{Point{200, 300}, LAYER::CHARACTER, 0, 0, 4, 4}, true));
    // TODO: Re-enable buttons when they do what they're supposed to do
    /*
    gameObjects.emplace_back(std::make_shared<DebugButton>(
            manager, Transform{Point{825, 800}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<ExitButton>(
            manager, Transform{Point{20, 40}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<SettingsButton>(
            manager, Transform{Point{1710, 40}, 100, 0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<ScoreboardButton>(
            manager, Transform{Point{800, 530}, 100, 0, 5, 5}, true));
    */
}
