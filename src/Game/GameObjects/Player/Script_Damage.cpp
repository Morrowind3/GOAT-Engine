#include "Script_Damage.hpp"
#include "../../Keys.hpp"

void Script_Damage::onExternalEvent() {
    if(_graceTimer < GRACE_PERIOD) return;
    _actor.audioSources.at(Keys::DAMAGE_SFX).queueForPlay = true;

    int currentHealth = std::stoi(_globals.gameGet(Keys::HP));
    _globals.gameStore(Keys::HP, std::to_string(--currentHealth));
    _graceTimer = 0;

    if(currentHealth <= 0) {
        _globals.gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFEAT);
    }

}

void Script_Damage::onUpdate(double deltaTime) {
    if(_graceTimer >= GRACE_PERIOD){
        _actor.transform.visible = true;
        return;
    }
    _graceTimer += deltaTime;

    // Blink for damage feedback
    if((int) _graceTimer % (GRACE_PERIOD / 6) < 25 ) {
        _actor.transform.visible = !_actor.transform.visible;
    }
}

void Script_Damage::onDestroy() {
    _actor.transform.visible = true;
}

