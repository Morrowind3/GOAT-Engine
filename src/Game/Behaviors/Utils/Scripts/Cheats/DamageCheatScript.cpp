#include "DamageCheatScript.hpp"
#include "../../../../Keys.hpp"

DamageCheatScript::DamageCheatScript(Player& player, bool active): Script(active), _player(player) {}

void DamageCheatScript::onUpdate(double deltaTime) {
    // 3 damages player
    if (_input.getKeyDown(KeyCode::NUMBER_3)) {
        _player.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}