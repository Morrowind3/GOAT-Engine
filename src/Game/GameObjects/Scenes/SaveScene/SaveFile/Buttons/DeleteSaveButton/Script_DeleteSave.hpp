#ifndef GOAT_ENGINE_SCRIPT_DELETESAVE_HPP
#define GOAT_ENGINE_SCRIPT_DELETESAVE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../../../../Engine/Utilities/Globals.hpp"
#include "../../../../../../../Engine/Utilities/EngineCalls.hpp"


using namespace Engine;

class Script_DeleteSave: public Script {
    public:
        Script_DeleteSave(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active);
        void onExternalEvent();

    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        int _saveNumber;
        bool _deletionState {false};
        Script& _loadSavesScript;
        AudioSource& _deleteSound;
};


#endif //GOAT_ENGINE_SCRIPT_DELETESAVE_HPP
