#include "Script_PlaySave.hpp"
#include "../../../../../../Keys.hpp"

Script_PlaySave::Script_PlaySave(int saveNumber, bool active): Script(active), _saveNumber{saveNumber} {
}

/// Load data of save file and parse to globals
void Script_PlaySave::onExternalEvent() {
    DataModel saveFile = _dataApi.get("Players", "id", std::to_string(_saveNumber));
    _globals.gameStore(Keys::CURRENT_PLAYER_ID, saveFile.getValue("id"));
    _globals.gameStore(Keys::ETAPPES_UNLOCKED, saveFile.getValue("EtappesUnlocked"));
    // Sava data loaded, so game can progress to the main menu
    _engineCalls.changeScene(Keys::MAIN_MENU);
}
