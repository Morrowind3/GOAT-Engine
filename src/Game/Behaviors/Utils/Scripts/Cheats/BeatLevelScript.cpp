#include "BeatLevelScript.hpp"
#include "../../../../Keys.hpp"

BeatLevelScript::BeatLevelScript(SceneManager& sceneManager, AudioSource& beatGameSfx, bool active): Script(active),
    _sceneManager{sceneManager}, _beatGameSfx{beatGameSfx} {
}

void BeatLevelScript::onUpdate(double deltaTime) {
    if (_activated) {
        if (!_activationTimer++) {
            _beatGameSfx.queueForPlay = true;
        }
        if (_activationTimer == 68) {
            _sceneManager.changeCurrentScene(Keys::VICTORY_SCREEN);
        }
    } else _activated = _input.getKeyDown(KeyCode::NUMBER_4);
}
