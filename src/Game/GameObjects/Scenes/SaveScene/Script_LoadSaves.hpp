#ifndef GOAT_ENGINE_SCRIPT_LOADSAVES_HPP
#define GOAT_ENGINE_SCRIPT_LOADSAVES_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/Scene.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_LoadSaves: public Script {
    public:
        explicit Script_LoadSaves(bool active);
        void onStart();
        void onExternalEvent();
    private:
        // Utilities
        EngineCalls& _engine = EngineCalls::getInstance();
        DataApi& _data = DataApi::getInstance();
        // Variables
        std::shared_ptr<Scene> _scene;
        // Constants
        const unsigned int EXPECTED_SAVE_FILE_AMOUNT {3};
        const unsigned short ETAPPE_AMOUNT {5};
        const int HIGHEST_POSSIBLE_ETAPPE_UNLOCKED {6};
        const int SAVE_FILE_HEIGHT {120};
        const int SAVE_FILE_TEXT_WIDTH {900};
        const int SAVE_FILE_BUTTON_WIDTH {110};
        // Helper methods
        void getActiveScene();
        void loadSaves();
        void resetSaveScreen();
        void createSaveFiles(unsigned int currentCount);
        int getTotalScoreForSave(int saveId);
};


#endif //GOAT_ENGINE_SCRIPT_LOADSAVES_HPP
