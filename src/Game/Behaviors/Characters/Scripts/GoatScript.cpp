//
// Created by Morrowind3 on 28/11/2021.
//

#include "GoatScript.hpp"
#include "../../../Keys.hpp"

void GoatScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) == other.tags.end()) return;
    other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
}
