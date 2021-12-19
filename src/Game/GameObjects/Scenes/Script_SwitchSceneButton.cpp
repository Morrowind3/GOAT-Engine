#include "Script_SwitchSceneButton.hpp"

Script_SwitchSceneButton::Script_SwitchSceneButton(std::string levelName, AudioSource* nopeSound, bool active):
        Script(active), _levelName{std::move(levelName)}, _nopeSound{nopeSound} {
}

Script_SwitchSceneButton::Script_SwitchSceneButton(std::string levelName, bool active):
        Script_SwitchSceneButton(std::move(levelName),nullptr,active){
}

void Script_SwitchSceneButton::onExternalEvent() {
    _debug.log("Switch scene script called towards " + _levelName);
    try {
        _engineCalls.changeScene(_levelName);
    } catch (const std::runtime_error& error) {
        _debug.log(error.what());
        if (_nopeSound != nullptr) _nopeSound->queueForPlay = true;
    }
}


