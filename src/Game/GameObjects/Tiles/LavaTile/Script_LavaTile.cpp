#include "Script_LavaTile.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

Script_LavaTile::Script_LavaTile(bool active) : Script(active) {}

void Script_LavaTile::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}