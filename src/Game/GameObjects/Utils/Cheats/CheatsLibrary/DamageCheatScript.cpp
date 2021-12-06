#include "DamageCheatScript.hpp"
#include "../../../../Keys.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

DamageCheatScript::DamageCheatScript(Object_Player& player, bool active): Script(active), _player(player) {}

void DamageCheatScript::onUpdate(double deltaTime) {
    // 2 damages player
    if (_input.getKeyDown(KeyCode::NUMBER_2)) {
        _player.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
    if (_input.getKeyDown(KeyCode::NUMBER_5)) {
        int currentHealth = std::stoi(Globals::getInstance().sceneGet(Keys::HP));
        Globals::getInstance().sceneStore(Keys::HP, std::to_string(++currentHealth));
    }
}