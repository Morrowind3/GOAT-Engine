#include "SwitchSceneButtonScript.hpp"

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, AudioSource* nopeSound, bool active):
        Script(active), _levelName{std::move(levelName)}, _nopeSound{nopeSound} {
}

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, bool active):
        SwitchSceneButtonScript(std::move(levelName),nullptr,active){
}

void SwitchSceneButtonScript::onExternalEvent() {
    _debug.log("Switch scene script called towards " + _levelName);
    try {
        _engineCalls.changeScene(_levelName);
    } catch (const std::runtime_error& error) {
        _debug.log(error.what());
        if (_nopeSound != nullptr) _nopeSound->queueForPlay = true;
    }
}


