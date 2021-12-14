#include "Scene_ScoreboardMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/MainMenuScene/Buttons/Object_BackToSaveScreenButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/ScoreboardScene/Object_ScoreboardManager.hpp"

Scene_ScoreboardMenu::Scene_ScoreboardMenu() : SceneTemplate_Menu(Keys::SCOREBOARD_MENU) {
    this->viewPort = Rectangle{{0,0}, 1280, 680}; // Zoom-in

    // Logic
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardManager>(true));

    // Buttons
    gameObjects.emplace_back(std::make_shared<Object_BackToSaveScreenButton>(
            Transform{Point{1000, 615}, LAYER::UI, 0,0, 3, 2}, true));
}