#include "Script_AnimateCreditsText.hpp"

Script_AnimateCreditsText::Script_AnimateCreditsText(std::vector<Text*> creditsText, bool active):
        Script(active), _creditsText{std::move(creditsText)} {
    _originalPosition = _creditsText.at(0)->location.position.x;
}

void Script_AnimateCreditsText::onUpdate(double deltaTime) {
    for (auto* text: _creditsText) {
        // Move 50px per second
        if (moveToRight) text->location.position.x += deltaTime/15.0;
        else text->location.position.x -= deltaTime/15.0;
    }
    // Moved over maximum leftwards position
    if (_originalPosition-MAXIMUM_DIFFERENCE > _creditsText.at(0)->location.position.x) {
        moveToRight = true;
    }
    // Moved over maximum rightwards position
    if (_originalPosition < _creditsText.at(0)->location.position.x) {
        moveToRight = false;
    }
}


