#include "Script_VictoryFlag.hpp"
#include "../../../Keys.hpp"

Script_VictoryFlag::Script_VictoryFlag(bool active, Object_VictoryFlag& flag) : Script(active), _flag(flag) {
}

void Script_VictoryFlag::onStart() {
    _globals.gameStore(Keys::FLAG_LOCATION, std::to_string(_flag.transform.position.x));
}

void Script_VictoryFlag::onUpdate(double deltaTime) {
    animationTimer += deltaTime;
    if(animationTimer >= 800) animateFlag();
}

void Script_VictoryFlag::animateFlag() {
    _flag.sprites.at("Default").active = !_flag.sprites.at("Default").active;
    _flag.sprites.at("Wave").active = !_flag.sprites.at("Wave").active;
    animationTimer = 0;
}

void Script_VictoryFlag::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) == other.tags.end()) return;
    Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_VICTORY);
}

