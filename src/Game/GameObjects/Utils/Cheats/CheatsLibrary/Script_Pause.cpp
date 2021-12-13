#include "Script_Pause.hpp"

Script_Pause::Script_Pause(AudioSource& pauseSound, bool active): Script(active), _pauseSound{pauseSound} {
}

void Script_Pause::onUpdate(double deltaTime) {
    // ESC key pauses
    if (_input.getKeyDown(KeyCode::ESCAPE)) {
        pauseLogic();
    }
}

void Script_Pause::onExternalEvent() {
    pauseLogic();
}

void Script_Pause::pauseLogic() {
    _engineCalls.pause(!_engineCalls.isPaused());
    _pauseSound.queueForPlay = true;
    if (_engineCalls.isPaused()) _debug.log("Game paused");
    else _debug.log("Game unpaused");
}
