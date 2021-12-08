#include "GameSceneManager.hpp"
#include "Keys.hpp"
#include "Scenes/Menus/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "Scenes/Menus/EtappeSelection.hpp"
#include "Scenes/Menus/ScoreboardMenuScene.hpp"
#include "Scenes/Menus/SettingsMenuScene.hpp"
#include "Scenes/Menus/DefeatScene.hpp"
#include "Scenes/Menus/VictoryScene.hpp"
#include "Scenes/Etappes/EtappeThree.hpp"
#include "Scenes/Etappes/EtappeFour.hpp"
#include "Scenes/Etappes/EtappeFive.hpp"
#include <stdexcept>

void GameSceneManager::changeCurrentScene(const std::string& name) {
    Debug::getInstance().log("Game scene manager will attempt to switch to scene: " + name);
    SceneManager& sceneManager = *this;

    if(name == Keys::CURRENT_ETAPPE) setEtappeScene();
    else if (name == Keys::NEXT_ETAPPE) {
        ++_currentEtappe;
        setEtappeScene();
    }
    else if (name == Keys::ETAPPE_ONE){
        _currentEtappe = 1;
        setEtappeScene();
    }
    else if (name == Keys::ETAPPE_TWO){
        _currentEtappe = 2;
        setEtappeScene();
    }
    else if (name == Keys::ETAPPE_THREE){
        _currentEtappe = 3;
        setEtappeScene();
    } else if (name == Keys::ETAPPE_FOUR) {
        _currentEtappe = 4;
        setEtappeScene();
    } else if (name == Keys::ETAPPE_FIVE) {
        _currentEtappe = 5;
        setEtappeScene();
    }
    else if (name == Keys::MAIN_MENU) _currentScene = std::make_shared<MainMenuScene>();
    else if (name == Keys::SCOREBOARD_MENU) _currentScene = std::make_shared<ScoreboardMenuScene>();
    else if (name == Keys::SETTINGS_MENU) _currentScene = std::make_shared<SettingsMenuScene>();
    else if (name == Keys::ETAPPE_SELECT) _currentScene = std::make_shared<EtappeSelection>();
    else if (name == Keys::DEFEAT_SCREEN) _currentScene = std::make_shared<DefeatScene>();
    else if (name == Keys::VICTORY_SCREEN) _currentScene = std::make_shared<VictoryScene>();
    else {
        throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted key: " + name);
    }
}

void GameSceneManager::setEtappeScene() {
    switch(_currentEtappe){
        case 1: _currentScene = std::make_shared<EtappeOne>();
            break;
        case 2: _currentScene = std::make_shared<EtappeTwo>();
            break;
        case 3: _currentScene = std::make_shared<EtappeThree>();
            break;
        case 4: _currentScene = std::make_shared<EtappeFour>();
            break;
        case 5: _currentScene = std::make_shared<EtappeFive>();
            break;
        default: throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted etappe number: " + std::to_string(_currentEtappe));
    }
}
