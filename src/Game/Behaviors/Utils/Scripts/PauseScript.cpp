#include "PauseScript.hpp"
#include "../../../Keys.hpp"

PauseScript::PauseScript(bool active): Script(active) { }

void PauseScript::OnStart() {
    _globals.sceneStore(Keys::PAUSE, Keys::FALSE);
}

void PauseScript::OnUpdate(double deltaTime) {
    // 1 key pauses
    if (_input.GetKeyDown(KeyCode::NUMBER_1)) {
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
}
