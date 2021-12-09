#include "SaveScene.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/SaveScene/SavesManager.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/ExitButton/ExitButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/SaveScene/Buttons/DebugButton/DebugButton.hpp"

SaveScene::SaveScene(): SceneTemplate_Menu(Keys::SAVE_MENU) {
    this->viewPort = Rectangle{{0,0}, 1280, 680};
    gameObjects.emplace_back(std::make_shared<SavesManager>(*this, true));
    gameObjects.emplace_back(std::make_shared<DebugButton>(
            Transform{Point{825, 580}, LAYER::UI, 0,0, 4, 4}, true));
    gameObjects.emplace_back(std::make_shared<ExitButton>(
            Transform{Point{500, 580}, LAYER::UI, 0,0, 4, 4}, true));
}
