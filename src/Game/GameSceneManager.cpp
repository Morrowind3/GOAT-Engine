#include "GameSceneManager.hpp"
#include "Keys.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "Scenes/Menus/Scene_MainMenu.hpp"
#include "Scenes/Etappes/Scene_EtappeOne.hpp"
#include "Scenes/Etappes/Scene_EtappeTwo.hpp"
#include "Scenes/Menus/Scene_EtappeSelectionMenu.hpp"
#include "Scenes/Menus/Scene_ScoreboardMenu.hpp"
#include "Scenes/Menus/Scene_SettingsMenu.hpp"
#include "Scenes/Menus/Scene_GameOverMenu.hpp"
#include "Scenes/Menus/Scene_VictoryMenu.hpp"
#include "Scenes/Etappes/Scene_EtappeThree.hpp"
#include "Scenes/Etappes/Scene_EtappeFour.hpp"
#include "Scenes/Etappes/Scene_EtappeFive.hpp"
#include "Scenes/Menus/Scene_SaveFileMenu.hpp"
#include "Scenes/Menus/Scene_CreditsMenu.hpp"
#include <stdexcept>

void GameSceneManager::changeCurrentScene(const std::string& name) {
    Debug::getInstance().log("Game scene manager will attempt to switch to scene: " + name);

    // Etappes
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
    // Menus
    else if (name == Keys::SAVE_MENU) _currentScene = std::make_shared<Scene_SaveFileMenu>();
    else if (name == Keys::MAIN_MENU) _currentScene = std::make_shared<Scene_MainMenu>();
    else if (name == Keys::SCOREBOARD_MENU) _currentScene = std::make_shared<Scene_ScoreboardMenu>();
    else if (name == Keys::SETTINGS_MENU) _currentScene = std::make_shared<Scene_SettingsMenu>();
    else if (name == Keys::ETAPPE_SELECT) _currentScene = std::make_shared<Scene_EtappeSelectionMenu>();
    else if (name == Keys::DEFEAT_SCREEN) _currentScene = std::make_shared<Scene_GameOverMenu>();
    else if (name == Keys::VICTORY_SCREEN) _currentScene = std::make_shared<Scene_VictoryMenu>();
    else if (name == Keys::CREDITS_MENU) _currentScene = std::make_shared<Scene_CreditsMenu>();
    else {
        throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted key: " + name);
    }
}

void GameSceneManager::setEtappeScene() {
    switch(_currentEtappe){
        case 1: _currentScene = std::make_shared<Scene_EtappeOne>();
            break;
        case 2: _currentScene = std::make_shared<Scene_EtappeTwo>();
            break;
        case 3: _currentScene = std::make_shared<Scene_EtappeThree>();
            break;
        case 4: _currentScene = std::make_shared<Scene_EtappeFour>();
            break;
        case 5: _currentScene = std::make_shared<Scene_EtappeFive>();
            break;
        default: throw std::runtime_error("GameSceneManager: No valid scene loaded in! Attempted etappe number: " + std::to_string(_currentEtappe));
    }
}
