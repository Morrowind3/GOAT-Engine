#include "IncreaseEtappeCountScript.hpp"
#include "../../../Keys.hpp"

IncreaseEtappeCountScript::IncreaseEtappeCountScript(bool active) : Script(active) {
}

void IncreaseEtappeCountScript::onStart() {
    int currentUnlockedLevel = std::stoi(_globals.gameGet(Keys::ETAPPE_SELECT));
    _globals.gameStore(Keys::ETAPPE_SELECT, std::to_string(++currentUnlockedLevel));
}
