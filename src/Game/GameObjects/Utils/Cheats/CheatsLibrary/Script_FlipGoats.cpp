#include "Script_FlipGoats.hpp"
#include "../../../../Keys.hpp"

Script_FlipGoats::Script_FlipGoats(AudioSource& activationSound, bool active)
    : Script(active), _activationSound{activationSound} {
}

void Script_FlipGoats::onUpdate(double deltaTime) {
    // H key flips all goats
    if (_input.getKeyDown(KeyCode::H)) {
        _activationSound.queueForPlay = true;
        if (!_activated) {
            _activated = true;
            _globals.sceneStore(Keys::GOAT_FLIP, Keys::TRUE);
        } else {
            _activated = false;
            _globals.sceneRemove(Keys::GOAT_FLIP);
        }
    }
}

