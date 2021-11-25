#include "GameSceneManager.hpp"
#include "Keys.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "Scenes/EtappeSelection.hpp"
#include "Scenes/ScoreboardMenuScene.hpp"
#include "Scenes/SettingsMenuScene.hpp"
#include <stdexcept>

void GameSceneManager::ChangeCurrentScene(const std::string& name) {
    Debug::GetInstance().log("Game scene manager will attempt to switch to scene: " + name);
    SceneManager& sceneManager = *this;
    if (name == Keys::MAIN_MENU) _currentScene = std::make_shared<MainMenuScene>(sceneManager);
    else if (name == Keys::SCOREBOARD_MENU) _currentScene = std::make_shared<ScoreboardMenuScene>(sceneManager);
    else if (name == Keys::SETTINGS_MENU) _currentScene = std::make_shared<SettingsMenuScene>(sceneManager);
    else if (name == Keys::ETAPPE_SELECT) _currentScene = std::make_shared<EtappeSelection>(sceneManager);
    else if (name == Keys::ETAPPE_ONE) _currentScene = std::make_shared<EtappeOne>(sceneManager);
    else if (name == Keys::ETAPPE_TWO) _currentScene = std::make_shared<EtappeTwo>(sceneManager);
    else throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted key: " + name);
}
