#include "Script_DamageCheat.hpp"
#include "../../../../Keys.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

Script_DamageCheat::Script_DamageCheat(Object_Player& player, bool active): Script(active), _player(player) {}

void Script_DamageCheat::onUpdate(double deltaTime) {
    // 2 damages player
    if (_input.getKeyDown(KeyCode::NUMBER_2)) {
        _player.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
    // TODO: Document in cheats menu and play Jägerpleister heal sfx
    // 5 heals player
    if (_input.getKeyDown(KeyCode::NUMBER_5)) {
        int currentHealth = std::stoi(_globals.gameGet(Keys::HP));
        _globals.gameStore(Keys::HP, std::to_string(++currentHealth));
    }
}