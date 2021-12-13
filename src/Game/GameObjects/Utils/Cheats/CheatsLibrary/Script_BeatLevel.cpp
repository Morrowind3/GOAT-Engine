#include "Script_BeatLevel.hpp"
#include "../../../../Keys.hpp"

Script_BeatLevel::Script_BeatLevel(AudioSource& beatGameSfx, bool active): Script(active),
     _beatGameSfx{beatGameSfx} {
}

void Script_BeatLevel::onUpdate(double deltaTime) {
    if (_activated) {
        if (_activationTimer <= 0.0) {
            _beatGameSfx.queueForPlay = true;
        }
        _activationTimer += deltaTime;
        if (_activationTimer >= BEAT_GAME_SFX_DURATION) {
            _engineCalls.changeScene(Keys::VICTORY_SCREEN);
        }
    } else _activated = _input.getKeyDown(KeyCode::NUMBER_4);
}
