#include "PauseScript.hpp"

PauseScript::PauseScript(AudioSource& pauseSound, bool active): Script(active), _pauseSound{pauseSound} {
}

void PauseScript::onUpdate(double deltaTime) {
    // 1 key pauses
    if (_input.getKeyDown(KeyCode::NUMBER_1)) {
        pauseLogic();
    }
}

void PauseScript::onExternalEvent() {
    pauseLogic();
}

void PauseScript::pauseLogic() {
    _engineCalls.pause(!_engineCalls.isPaused());
    _pauseSound.queueForPlay = true;
    if (_engineCalls.isPaused()) _debug.log("Game paused");
    else _debug.log("Game unpaused");
}
