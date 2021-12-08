#include "SaveScene.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/SaveScene/SavesManager.hpp"

SaveScene::SaveScene(): SceneTemplate_Menu(Keys::SAVE_MENU) {
    this->viewPort = Rectangle{{0,0}, 1280, 680};
    gameObjects.emplace_back(std::make_shared<SavesManager>(*this, true));
}
