#include "Scene_SaveFileMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/SaveScene/Object_SavesManager.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/ExitButton/Object_ExitButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/DebugButton/Object_DebugButton.hpp"
#include "../../GameObjects/Scenes/SaveScene/Decor/Object_CoolGoat.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/Object_ScoreboardButton.hpp"

Scene_SaveFileMenu::Scene_SaveFileMenu(): SceneTemplate_Menu(Keys::SAVE_MENU) {
    this->_viewPort = Rectangle{{0, 0}, 1280, 680}; // Zoom-in

    // Logic
    gameObjects.emplace_back(std::make_shared<Object_SavesManager>(true));

    // Buttons
    gameObjects.emplace_back(std::make_shared<Object_ScoreboardButton>(
            Transform{Point{150, 580}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<Object_ExitButton>(
            Transform{Point{555, 580}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<Object_DebugButton>(
            Transform{Point{825, 580}, LAYER::UI, 0,0, 4, 4}, true));

    // Decor
    gameObjects.emplace_back(std::make_shared<Object_CoolGoat>(
            Transform{{1196,248},LAYER::CHARACTER,0,0,4,4}, true));

}
