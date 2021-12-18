#include "Script_DeleteSave.hpp"

Script_DeleteSave::Script_DeleteSave(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active): Script(active),
    _saveNumber{saveNumber}, _loadSavesScript{loadSavesScript}, _deleteSound{deleteSound} {
}

/// Delete data of save
void Script_DeleteSave::onExternalEvent() {
    _deletionState = true;
    std::string playerIdString {std::to_string(_saveNumber)};

    // Reset save file's etappe progress
    DataModel saveFile = _dataApi.get("Players", "id", std::to_string(_saveNumber));
    saveFile.setValue("EtappesUnlocked", "1");
    _dataApi.update(saveFile);

    // Reset save file's high scores
    auto highScores = _dataApi.getAll("HighScores");
    for (auto& highScore: highScores) {
        if (highScore.getValue("Players_id") == playerIdString) {
            highScore.setValue("Score", "0");
            _dataApi.update(highScore);
        }
    }

    // Reload saves
    _deleteSound.queueForPlay = true;
    _loadSavesScript.onExternalEvent();
}

