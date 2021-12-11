#ifndef GOAT_ENGINE_PLAYSAVESCRIPT_HPP
#define GOAT_ENGINE_PLAYSAVESCRIPT_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../../../../Engine/Utilities/Globals.hpp"
#include "../../../../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class PlaySaveScript: public Script {
    public:
        PlaySaveScript(int saveNumber, bool active);
        void onExternalEvent();
    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        int _saveNumber;
};


#endif //GOAT_ENGINE_PLAYSAVESCRIPT_HPP
