#include "Script_LoadSaves.hpp"

#include "../../../Layers.hpp"
#include "SaveFile/Object_SaveFile.hpp"
#include "SaveFile/Buttons/PlaySaveButton/Object_PlaySaveButton.hpp"
#include "SaveFile/Buttons/DeleteSaveButton/Object_DeleteSaveButton.hpp"
#include "../../../Keys.hpp"

Script_LoadSaves::Script_LoadSaves(Scene& scene, bool active): Script(active), _scene{scene} {
}

// Show the altitude to the user
static int etappesUnlockedToAltitude(int etappesUnlocked) {
    switch (etappesUnlocked) {
        case 2: return 1800;
        case 3: return 3700;
        case 4: return 5000;
        case 5: return 6640;
        case 6: return 8848;
        default: return 0;
    }
}

/// Load all saves on start
void Script_LoadSaves::onStart() {
    loadSaves();
}

/// If this was called externally, saves are already on screen, so first clear the saves from screen and then reload
void Script_LoadSaves::onExternalEvent() {
    resetSaveScreen();
    loadSaves();
}

/// Get all saves and display them on screen, with the save file position moving around to correctly place each object
void Script_LoadSaves::loadSaves() {
    Transform saveFilePosition {{50,150}, LAYER::UI, 0, 0, 4, 4};
    createSaveFiles(_data.getAll("Players").size());
    auto saves = _data.getAll("Players", "id", false);
    for(auto& save: saves) {
        // Extract information from column
        int saveId = std::stoi(save.getValue("id"));
        int etappesUnlocked = std::stoi(save.getValue("EtappesUnlocked"));
        int altitude = etappesUnlockedToAltitude(etappesUnlocked);
        int maxAltitude = etappesUnlockedToAltitude(HIGHEST_POSSIBLE_ETAPPE_UNLOCKED);
        int score = 0; // TODO: Score from the high score table

        // Add save file and associated buttons to scene
        _scene.gameObjects.emplace_back(std::make_shared<Object_SaveFile>(saveId, altitude, maxAltitude, score, saveFilePosition, true));

        saveFilePosition.position.x += SAVE_FILE_TEXT_WIDTH;
        saveFilePosition.scaleWidth = saveFilePosition.scaleHeight -= 1;
        _scene.gameObjects.emplace_back(std::make_shared<Object_PlaySaveButton>(saveId,saveFilePosition,true));

        saveFilePosition.position.x += SAVE_FILE_BUTTON_WIDTH;
        _scene.gameObjects.emplace_back(std::make_shared<Object_DeleteSaveButton>(saveId,*this,saveFilePosition,true));

        // Reset for next save
        saveFilePosition.position.x -= SAVE_FILE_TEXT_WIDTH + SAVE_FILE_BUTTON_WIDTH;
        saveFilePosition.position.y += SAVE_FILE_HEIGHT;
        saveFilePosition.scaleWidth = saveFilePosition.scaleHeight += 1;
    }
}

/// Removes every object associated with save files so the save files can reload
void Script_LoadSaves::resetSaveScreen() {
    for (auto& gameObject: _scene.gameObjects) {
        if (gameObject->hasTag(Keys::SAVE_FILE)) gameObject->queueForDestruction = true;
    }
}

/// Create all missing save files
void Script_LoadSaves::createSaveFiles(unsigned int currentCount) {
    // For eg: if three save files are expected, and two exist, make one additional save file
    for (unsigned int saveFileNumber = EXPECTED_SAVE_FILE_AMOUNT-currentCount; saveFileNumber > 0; --saveFileNumber) {
        DataModel saveFile("Players");
        saveFile.setValue("EtappesUnlocked", "1");
        saveFile.setValue("Difficulty", "100");
        saveFile.setValue("Volume", "100");
        _data.insert(saveFile);
    }
}