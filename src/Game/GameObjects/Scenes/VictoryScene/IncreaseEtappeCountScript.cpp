#include "IncreaseEtappeCountScript.hpp"
#include "../../../Keys.hpp"

IncreaseEtappeCountScript::IncreaseEtappeCountScript(bool active) : Script(active) {
}

void IncreaseEtappeCountScript::onStart() {
    // Get required data from globals
    int playerId = std::stoi(_globals.gameGet(Keys::CURRENT_PLAYER_ID));
    int currentUnlockedLevel = std::stoi(_globals.gameGet(Keys::ETAPPES_UNLOCKED));
    // Save progress in game scope
    _globals.gameStore(Keys::ETAPPES_UNLOCKED, std::to_string(++currentUnlockedLevel));
    // Save progress in DB
    auto save = _dataApi.get("Players", "id", std::to_string(playerId));
    save.setValue("EtappesUnlocked", std::to_string(currentUnlockedLevel));
    _dataApi.update(save);
}
