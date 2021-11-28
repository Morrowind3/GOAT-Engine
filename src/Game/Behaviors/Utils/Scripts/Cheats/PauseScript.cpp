#include "PauseScript.hpp"
#include "../../../../Keys.hpp"

PauseScript::PauseScript(AudioSource& pauseSound, bool active): Script(active), _pauseSound{pauseSound} { }

void PauseScript::onStart() {
    _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
}

void PauseScript::onUpdate(double deltaTime) {
    // 1 key pauses
    if (_input.getKeyDown(KeyCode::NUMBER_1)) {
        pauseLogic();
        if (_isPaused) Debug::getInstance().log("Game paused");
        else Debug::getInstance().log("Game unpaused");
    }
}

void PauseScript::onExternalEvent() {
    pauseLogic();
}

void PauseScript::onDestroy() {
    _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
}

void PauseScript::pauseLogic() {
    if(_isPaused) _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
    else          _globals.sceneStore(Keys::PAUSE, Keys::TRUE);
    _isPaused = !_isPaused;
    _pauseSound.queueForPlay = true;
}
