#include "DamageCheatScript.hpp"
#include "../../../../Keys.hpp"

DamageCheatScript::DamageCheatScript(Player& player, bool active): Script(active), _player(player) {}

void DamageCheatScript::onUpdate(double deltaTime) {
    // 2 damages player
    if (_input.getKeyDown(KeyCode::NUMBER_2)) {
        _player.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}