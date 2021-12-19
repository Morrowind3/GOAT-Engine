#include "Script_FpsMeter.hpp"
#include "../../../Keys.hpp"

#include <cmath>

Script_FpsMeter::Script_FpsMeter(Text& fpsText, bool active):
        Script(active), _text{fpsText} {
}

void Script_FpsMeter::onStart() {
    _text.active = false;
    if (_globals.gameExists(Keys::FPS)) {
        auto shouldFpsBeEnabled = _globals.gameGet(Keys::FPS);
        if (shouldFpsBeEnabled == Keys::TRUE) _text.active = true;
    } else {
        _globals.gameStore(Keys::FPS, Keys::FALSE);
    }
}

void Script_FpsMeter::onUpdate(double deltaTime) {
    // 1 toggles FPS
    if (_input.getKeyDown(KeyCode::NUMBER_1)) {
        _text.active = !_text.active;
        // Update FPS visibility status throughout the game
        if (_text.active)  {
            _globals.gameStore(Keys::FPS, Keys::TRUE);
            _debug.log("Enabled FPS counter");
        }
        else {
            _globals.gameStore(Keys::FPS, Keys::FALSE);
            _debug.log("Disabled FPS counter");
        }
    }

    if (_text.active) {
        // One extra FPS needed because of SDL Tick rounding issues
        const int fps = 1 + (int)std::round(1000/_clock.lastRecordedUnmodifiedDeltaTime());
        _text.text = std::to_string(fps);
    }
}


