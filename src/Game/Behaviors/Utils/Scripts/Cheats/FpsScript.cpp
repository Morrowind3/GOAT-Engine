#include "FpsScript.hpp"

#include <cmath>

FpsScript::FpsScript(Text& fpsText, bool active):
        Script(active), _text{fpsText} {
}

void FpsScript::onUpdate(double deltaTime) {
    // 1 toggles FPS
    if (_input.getKeyDown(KeyCode::NUMBER_1)) {
        _text.active = !_text.active;
        if (_text.active) Debug::getInstance().log("Enabled FPS counter");
        else Debug::getInstance().log("Disabled FPS counter");
    }

    if (_text.active) {
        // One extra FPS needed because of SDL Tick rounding issues
        _text.text = std::to_string(1+(int)std::round(1000/_clock.lastRecordedUnmodifiedDeltaTime()));
    }

}
