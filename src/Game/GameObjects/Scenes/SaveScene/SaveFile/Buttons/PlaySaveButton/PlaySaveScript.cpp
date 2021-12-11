#include "PlaySaveScript.hpp"
#include "../../../../../../Keys.hpp"

PlaySaveScript::PlaySaveScript(int saveNumber, bool active): Script(active), _saveNumber{saveNumber} {
}

/// Load data of save file and parse to globals
void PlaySaveScript::onExternalEvent() {
    DataModel saveFile = _dataApi.get("Players", "id", std::to_string(_saveNumber));
    _globals.gameStore(Keys::CURRENT_PLAYER_ID, saveFile.getValue("id"));
    _globals.gameStore(Keys::ETAPPES_UNLOCKED, saveFile.getValue("EtappesUnlocked"));
    _globals.gameStore(Keys::DIFFICULTY, saveFile.getValue("Difficulty"));
    _globals.gameStore(Keys::VOLUME, saveFile.getValue("Volume"));
    // Sava data loaded, so game can progress to the main menu
    _engineCalls.changeScene(Keys::MAIN_MENU);
}
