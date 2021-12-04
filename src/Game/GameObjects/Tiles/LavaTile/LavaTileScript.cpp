#include "LavaTileScript.hpp"
#include "../../../Keys.hpp"
#include "../../../Engine/API/GameObjects/GameObject.hpp"

LavaTileScript::LavaTileScript(bool active) : Script(active) {}

void LavaTileScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}