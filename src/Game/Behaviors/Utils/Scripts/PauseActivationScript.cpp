#include "PauseActivationScript.hpp"

PauseActivationScript::PauseActivationScript(GameObject& toggleObject, bool activeOnPause, bool active):
        Script(active), _toggleObject{&toggleObject}, _toggleComponent{nullptr}, _activeOnPause{activeOnPause} {
}

PauseActivationScript::PauseActivationScript(GameComponent& toggleComponent, bool activeOnPause, bool active):
        Script(active), _toggleObject{nullptr}, _toggleComponent{&toggleComponent}, _activeOnPause{activeOnPause} {
}

void PauseActivationScript::onStart() {
    checkPauseState();
}

void PauseActivationScript::onUpdate(double deltaTime) {
    checkPauseState();
}

void PauseActivationScript::checkPauseState() {
    if (_engineCalls.isPaused()) {
        if (_toggleObject != nullptr) _toggleObject->active = _activeOnPause;
        if (_toggleComponent != nullptr) _toggleComponent->active = _activeOnPause;
    }
    else {
        if (_toggleObject != nullptr) _toggleObject->active = !_activeOnPause;
        if (_toggleComponent != nullptr) _toggleComponent->active = !_activeOnPause;
    }
}




