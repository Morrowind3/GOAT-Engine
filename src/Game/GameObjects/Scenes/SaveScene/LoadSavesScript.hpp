#ifndef GOAT_ENGINE_LOADSAVESSCRIPT_HPP
#define GOAT_ENGINE_LOADSAVESSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/Scene.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"

using namespace Engine;

class LoadSavesScript: public Script {
    public:
        LoadSavesScript(Scene& scene, bool active);
        void onStart();
    private:
        // Utilities
        DataApi& _data = DataApi::getInstance();

        // Variables
        Scene& _scene;

        // Constants
        const int HIGHEST_POSSIBLE_ETAPPE_UNLOCKED {6};
        const int SAVE_FILE_HEIGHT {120};
        const int SAVE_FILE_TEXT_WIDTH {900};
        const int SAVE_FILE_BUTTON_WIDTH {110};
};


#endif //GOAT_ENGINE_LOADSAVESSCRIPT_HPP
