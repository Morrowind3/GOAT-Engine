#include "DeleteSaveScript.hpp"

DeleteSaveScript::DeleteSaveScript(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active): Script(active),
    _saveNumber{saveNumber}, _loadSavesScript{loadSavesScript}, _deleteSound{deleteSound} {
}

/// Delete data of save
void DeleteSaveScript::onExternalEvent() {
    _deletionState = true;
    std::string playerIdString {std::to_string(_saveNumber)};
    // "Reset" save file
    DataModel saveFile = _dataApi.get("Players", "id", std::to_string(_saveNumber));
    saveFile.setValue("EtappesUnlocked", "1");
    saveFile.setValue("Difficulty", "100");
    saveFile.setValue("Volume", "100");
    _dataApi.update(saveFile);
    // TODO: Delete all high scores (this crashes atm)
    //DataModel highScores = _dataApi.get("HighScores", "Players_id", playerIdString);
    //_dataApi.remove(highScores);
    // Reload saves
    _deleteSound.queueForPlay = true;
    _loadSavesScript.onExternalEvent();
}

