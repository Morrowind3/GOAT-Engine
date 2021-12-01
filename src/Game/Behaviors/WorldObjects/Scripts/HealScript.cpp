#include "HealScript.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

HealScript::HealScript(HealthPickup& pickup, AudioSource& healSfx, bool active): Script(active),
    _pickup(pickup), _healSfx{healSfx}, _originalY(pickup.transform.position.y){
}

void HealScript::onTriggerEnter2D(GameObject& other) {
    if(_queueForDeactivation > 0 || other.tags.find(Keys::PLAYER) == other.tags.end()) return;
    int currentHealth = std::stoi(Globals::getInstance().sceneGet(Keys::HP));
    if(currentHealth == 3) currentHealth = 2; // Make sure to not exceed the maximum health //TODO: Max health based on difficulty?
    Globals::getInstance().sceneStore(Keys::HP, std::to_string(++currentHealth));
    _healSfx.queueForPlay = true;
    _queueForDeactivation = 1;
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
    // TODO: Play sound with onDestroy instead of this hacky method
    if (_queueForDeactivation == 2) {
        _pickup.active = false;
        return;
    }
    if (_queueForDeactivation == 1) _queueForDeactivation++;
}
