#include "GameSceneManager.hpp"
#include "Keys.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "Scenes/EtappeSelection.hpp"
#include "Scenes/ScoreboardMenuScene.hpp"
#include "Scenes/SettingsMenuScene.hpp"
#include "Scenes/DefeatScene.hpp"
#include "Scenes/VictoryScene.hpp"
#include <stdexcept>

void GameSceneManager::changeCurrentScene(const std::string& name) {
    Debug::getInstance().log("Game scene manager will attempt to switch to scene: " + name);
    SceneManager& sceneManager = *this;

    if(name == Keys::CURRENT_ETAPPE) setEtappeScene();
    else if (name == Keys::NEXT_ETAPPE) {
        ++currentEtappe;
        setEtappeScene();
    }
    else if (name == Keys::ETAPPE_ONE){
        currentEtappe = 1;
        setEtappeScene();
    }
    else if (name == Keys::ETAPPE_TWO){
        currentEtappe = 2;
        setEtappeScene();
    }
    else if (name == Keys::MAIN_MENU) _currentScene = std::make_shared<MainMenuScene>(sceneManager);
    else if (name == Keys::SCOREBOARD_MENU) _currentScene = std::make_shared<ScoreboardMenuScene>(sceneManager);
    else if (name == Keys::SETTINGS_MENU) _currentScene = std::make_shared<SettingsMenuScene>(sceneManager);
    else if (name == Keys::ETAPPE_SELECT) _currentScene = std::make_shared<EtappeSelection>(sceneManager);
    else if (name == Keys::DEFEAT_SCREEN) _currentScene = std::make_shared<DefeatScene>(sceneManager);
    else if (name == Keys::VICTORY_SCREEN) _currentScene = std::make_shared<VictoryScene>(sceneManager);
    else {
        _currentScene = std::make_shared<MainMenuScene>(sceneManager);
        throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted key: " + name);
    }
}

// TODO: Is this needed?
void GameSceneManager::setEtappeScene() {
    switch(currentEtappe){
        case 1:  _currentScene = std::make_shared<EtappeOne>(*this);
            break;
        case 2:  _currentScene = std::make_shared<EtappeTwo>(*this);
            break;
    }
}
