#include "GameSceneManager.hpp"
#include "Keys.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include <stdexcept>

void GameSceneManager::ChangeCurrentScene(const std::string& name) {
    Debug::GetInstance().log("Game scene manager will attempt to switch to scene: " + name);
    SceneManager& sceneManager = *this;
    if (name == Keys::MAIN_MENU) _currentScene = std::make_shared<MainMenuScene>(sceneManager);
    if (name == Keys::ETAPPE_ONE) _currentScene = std::make_shared<EtappeOne>(sceneManager);
    if (name == Keys::ETAPPE_TWO) _currentScene = std::make_shared<EtappeTwo>(sceneManager);
    if (!_currentScene) throw std::runtime_error("No valid scene loaded in! Attempted key: " + name);
}
