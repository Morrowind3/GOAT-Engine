#include "FlagScript.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

FlagScript::FlagScript(bool active, VictoryFlag& flag) : Script(active), _flag(flag) {
}
void FlagScript::onUpdate(double deltaTime) {
    animationTimer += deltaTime;
    if(animationTimer >= 800) animateFlag();
}

void FlagScript::animateFlag() {
    _flag.sprites.at("Default").active = !_flag.sprites.at("Default").active;
    _flag.sprites.at("Wave").active = !_flag.sprites.at("Wave").active;
    animationTimer = 0;
}

void FlagScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) == other.tags.end()) return;
    Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_VICTORY);
}

