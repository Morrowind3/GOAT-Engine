//
// Created by Morrowind3 on 29/11/2021.
//

#include "HealScript.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

void HealScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) == other.tags.end()) return;
    int currentHealth = std::stoi(Globals::getInstance().sceneGet(Keys::HP));
    if(currentHealth == 3) return;
    Globals::getInstance().sceneStore(Keys::HP, std::to_string(++currentHealth));
    _pickup.active = false;
}