#include "Script_Heal.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

Script_Heal::Script_Heal(Object_HealthPickup& pickup, AudioSource& healSfx, bool active): Script(active),
    _pickup(pickup), _healSfx{healSfx}, _originalY(pickup.transform.position.y){
}

void Script_Heal::onTriggerEnter2D(GameObject& other) {
    if(!other.hasTag(Keys::PLAYER)) return;
    int currentHealth = std::stoi(_globals.gameGet(Keys::HP));
    if(currentHealth == 3) currentHealth = 2; // Make sure to not exceed the maximum health //TODO: Max health based on difficulty?
    _globals.gameStore(Keys::HP, std::to_string(++currentHealth));
    _healSfx.queueForPlay = true;
    _pickup.queueForDestruction = true;
}


void Script_Heal::onUpdate(double deltaTime) {
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
