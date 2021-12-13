#ifndef GOAT_ENGINE_SCRIPT_PLAYSAVE_HPP
#define GOAT_ENGINE_SCRIPT_PLAYSAVE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../../../../Engine/Utilities/Globals.hpp"
#include "../../../../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_PlaySave: public Script {
    public:
        Script_PlaySave(int saveNumber, bool active);
        void onExternalEvent();
    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        int _saveNumber;
};


#endif //GOAT_ENGINE_SCRIPT_PLAYSAVE_HPP
