#include "Script_DamageCheat.hpp"
#include "../../../../Keys.hpp"

Script_DamageCheat::Script_DamageCheat(Object_Player& player, AudioSource& healSound, bool active):
    Script(active), _player{player}, _healSound{healSound} {
}

void Script_DamageCheat::onUpdate(double deltaTime) {
    // 3 damages player
    if (_input.getKeyDown(KeyCode::NUMBER_3)) {
        _player.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
    // 4 heals player
    if (_input.getKeyDown(KeyCode::NUMBER_4)) {
        _globals.gameStore(Keys::HP, "3");
        _healSound.queueForPlay = true;
    }
}