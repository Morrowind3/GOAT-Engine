#include "LoadSavesScript.hpp"

#include "../../../Layers.hpp"
#include "SaveFile/SaveFile.hpp"
#include "SaveFile/Buttons/PlaySaveButton/PlaySaveButton.hpp"
#include "SaveFile/Buttons/DeleteSaveButton/DeleteSaveButton.hpp"

LoadSavesScript::LoadSavesScript(Scene& scene, bool active): Script(active), _scene{scene} {
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

/// Get all saves and display them on screen
void LoadSavesScript::onStart() {
    Transform saveFilePosition {{50,150}, LAYER::UI, 0, 0, 4, 4};
    auto saves = _data.getAll("Players", "id", false);
    for(auto& save: saves) {
        // Extract information from column
        int saveId = std::stoi(save.getValue("id"));
        int etappesUnlocked = std::stoi(save.getValue("EtappesUnlocked"));
        int altitude = etappesUnlockedToAltitude(etappesUnlocked);
        int maxAltitude = etappesUnlockedToAltitude(HIGHEST_POSSIBLE_ETAPPE_UNLOCKED);
        int score = 0; // TODO: Score from the high score table

        // Add save file and associated buttons to scene
        _scene.gameObjects.emplace_back(std::make_shared<SaveFile>(saveId, altitude, maxAltitude, score, saveFilePosition, true));
        saveFilePosition.position.x += SAVE_FILE_TEXT_WIDTH;
        saveFilePosition.scaleWidth = saveFilePosition.scaleHeight -= 1;
        _scene.gameObjects.emplace_back(std::make_shared<PlaySaveButton>(saveId,saveFilePosition,true));
        saveFilePosition.position.x += SAVE_FILE_BUTTON_WIDTH;
        _scene.gameObjects.emplace_back(std::make_shared<DeleteSaveButton>(saveId,saveFilePosition,true));
        saveFilePosition.position.x -= SAVE_FILE_TEXT_WIDTH + SAVE_FILE_BUTTON_WIDTH;
        saveFilePosition.position.y += SAVE_FILE_HEIGHT;
        saveFilePosition.scaleWidth = saveFilePosition.scaleHeight += 1;
    }
}
