#include "Script_PauseActivation.hpp"

Script_PauseActivation::Script_PauseActivation(GameObject& toggleObject, bool activeOnPause, bool active):
        Script(active), _toggleObject{&toggleObject}, _toggleComponent{nullptr}, _activeOnPause{activeOnPause} {
}

Script_PauseActivation::Script_PauseActivation(GameComponent& toggleComponent, bool activeOnPause, bool active):
        Script(active), _toggleObject{nullptr}, _toggleComponent{&toggleComponent}, _activeOnPause{activeOnPause} {
}

void Script_PauseActivation::onStart() {
    checkPauseState();
}

void Script_PauseActivation::onUpdate(double deltaTime) {
    checkPauseState();
}

void Script_PauseActivation::checkPauseState() {
    if (_engineCalls.isPaused()) {
        if (_toggleObject != nullptr) _toggleObject->active = _activeOnPause;
        if (_toggleComponent != nullptr) _toggleComponent->active = _activeOnPause;
    }
    else {
        if (_toggleObject != nullptr) _toggleObject->active = !_activeOnPause;
        if (_toggleComponent != nullptr) _toggleComponent->active = !_activeOnPause;
    }
}




