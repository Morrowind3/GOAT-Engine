#include "SwitchSceneButtonScript.hpp"

#include <utility>
#include "../../../Engine/Utilities/Debug.hpp"

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, SceneManager& sceneManager, AudioSource* nopeSound, bool active):
        Script(active), _levelName{std::move(levelName)}, _sceneManager{sceneManager}, _nopeSound{nopeSound} {
}

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, SceneManager& sceneManager, bool active):
        SwitchSceneButtonScript(std::move(levelName),sceneManager,nullptr,active){
}

void SwitchSceneButtonScript::onExternalEvent() {
    _debug.log("Switch scene script called towards " + _levelName);
    try {
        _sceneManager.changeCurrentScene(_levelName);
    } catch (const std::runtime_error& error) {
        _debug.log(error.what());
        if (_nopeSound != nullptr) _nopeSound->queueForPlay = true;
    }
}


