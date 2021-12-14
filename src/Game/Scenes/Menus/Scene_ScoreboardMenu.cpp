#include "Scene_ScoreboardMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Buttons/Object_BackToSaveScreenButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Object_ScoreboardManager.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Buttons/Object_ScoreboardSpecificEtappeButton.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Buttons/Object_ScoreboardAllEtappesButton.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Decor/Rain/Object_Rain.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Decor/Object_ScoreboardForeground.hpp"

Scene_ScoreboardMenu::Scene_ScoreboardMenu() : SceneTemplate_Menu(Keys::SCOREBOARD_MENU) {
    this->viewPort = Rectangle{{0,0}, 1280, 680}; // Zoom-in

    // Places scoreboard manager and extracts the scoreboard header text to feed to the buttons
    auto& scoreboardHeader = gameObjects.emplace_back(std::make_shared<Object_ScoreboardManager>(true))->text.at(Keys::TEXT);

    // Buttons
    // All etappes filter
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardAllEtappesButton>(scoreboardHeader,
                Transform{Point{90, 600}, LAYER::UI, 0,0, 2, 2}, true));
    // Etappe filters
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardSpecificEtappeButton>(1, scoreboardHeader,
            Transform{Point{200, 600}, LAYER::UI, 0,0, 2, 2}, true));
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardSpecificEtappeButton>(2, scoreboardHeader,
            Transform{Point{270, 600}, LAYER::UI, 0,0, 2, 2}, true));
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardSpecificEtappeButton>(3, scoreboardHeader,
            Transform{Point{340, 600}, LAYER::UI, 0,0, 2, 2}, true));
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardSpecificEtappeButton>(4, scoreboardHeader,
            Transform{Point{410, 600}, LAYER::UI, 0,0, 2, 2}, true));
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardSpecificEtappeButton>(5, scoreboardHeader,
            Transform{Point{480, 600}, LAYER::UI, 0,0, 2, 2}, true));
    // Back to save screen
    gameObjects.emplace_back(std::make_shared<Object_BackToSaveScreenButton>(
            Transform{Point{1000, 615}, LAYER::UI, 0,0, 3, 2}, true));

    // Decor
    gameObjects.emplace_back(std::make_shared<Object_Rain>(Transform{{}, 1,0,0,5,5}, true));
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardForeground>(Transform{{}, 2},true));
}