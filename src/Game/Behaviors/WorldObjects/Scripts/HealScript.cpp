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

void HealScript::onUpdate(double deltaTime) {
    _animationtimer += deltaTime;

    double y = _pickup.transform.position.y;
        if (_movingUp) {
            _pickup.transform.position.y = _pickup.transform.position.y -0.5;
            if(y < _originalY - 20) _movingUp = false;
        } else {
            _pickup.transform.position.y = _pickup.transform.position.y +0.5;
            if(y > _originalY + 20) _movingUp = true;
        _animationtimer = 0;
    }
}

HealScript::HealScript(HealthPickup& pickup, bool active) : Script(active), _pickup(pickup), _originalY(pickup.transform.position.y){
    //TODO: This shouldn't be in the script but for some reason this doesn't work when I set it in the object.
//    _pickup.transform.rotation = _pickup.transform.rotation - 45;
}
