#include "Script_IncreaseEtappeCount.hpp"
#include "../../../Keys.hpp"

Script_IncreaseEtappeCount::Script_IncreaseEtappeCount(bool active) : Script(active) {
}

void Script_IncreaseEtappeCount::onStart() {
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
