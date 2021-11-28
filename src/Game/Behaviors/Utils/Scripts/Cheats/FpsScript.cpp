#include "FpsScript.hpp"

#include <cmath>

FpsScript::FpsScript(Text& fpsText, bool active):
        Script(active), _text{fpsText} {
}

void FpsScript::OnUpdate(double deltaTime) {
    // End key toggles FPS
    if (_input.GetKeyDown(KeyCode::NUMBER_2)) {
        _text.active = !_text.active;
        if (_text.active) Debug::GetInstance().log("Enabled FPS counter");
        else              Debug::GetInstance().log("Disabled FPS counter");
    }

    // One extra FPS needed because of SDL Tick rounding issues
    if (_text.active) _text.text = std::to_string(1+(int)std::round(1000/deltaTime));
}
