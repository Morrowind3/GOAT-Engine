#include "PauseScript.hpp"
#include "../../../Keys.hpp"

PauseScript::PauseScript(AudioSource& pauseSound, bool active):
    Script(active), pauseSound{pauseSound} {
}

void PauseScript::OnStart() {
    _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
}

void PauseScript::OnUpdate(double deltaTime) {
    // ESC key pauses
    if (_input.GetKeyDown(KeyCode::ESCAPE)) {
        pauseLogic();
    }
}

void PauseScript::OnExternalEvent() {
    pauseLogic();
}

void PauseScript::OnDestroy() {
    _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
}

void PauseScript::pauseLogic() {
    if(_isPaused) _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
    else          _globals.sceneStore(Keys::PAUSE, Keys::TRUE);
    _isPaused = !_isPaused;
    pauseSound.queueForPlay = true;
}
