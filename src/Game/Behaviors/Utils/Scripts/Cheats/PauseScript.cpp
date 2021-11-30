#include "PauseScript.hpp"

PauseScript::PauseScript(AudioSource& pauseSound, bool active): Script(active), _pauseSound{pauseSound} {
}

void PauseScript::onUpdate(double deltaTime) {
    // ESC key pauses
    if (_input.getKeyDown(KeyCode::ESCAPE)) {
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
