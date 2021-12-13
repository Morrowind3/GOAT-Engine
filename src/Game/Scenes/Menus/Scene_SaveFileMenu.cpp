#include "Scene_SaveFileMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/SaveScene/Object_SavesManager.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/ExitButton/Object_ExitButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/DebugButton/Object_DebugButton.hpp"
#include "../../GameObjects/Scenes/SaveScene/Decor/Object_CoolGoat.hpp"

Scene_SaveFileMenu::Scene_SaveFileMenu(): SceneTemplate_Menu(Keys::SAVE_MENU) {
    this->viewPort = Rectangle{{0,0}, 1280, 680};
    gameObjects.emplace_back(std::make_shared<Object_SavesManager>(*this, true));
    gameObjects.emplace_back(std::make_shared<Object_CoolGoat>(
            Transform{{1196,248},LAYER::CHARACTER,0,0,4,4}, true));
    gameObjects.emplace_back(std::make_shared<Object_DebugButton>(
            Transform{Point{825, 580}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<Object_ExitButton>(
            Transform{Point{500, 580}, LAYER::UI, 0,0, 4, 4}, true));
}
