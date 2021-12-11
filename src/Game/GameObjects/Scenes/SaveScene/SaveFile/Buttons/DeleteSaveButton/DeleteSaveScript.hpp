#ifndef GOAT_ENGINE_DELETESAVESCRIPT_HPP
#define GOAT_ENGINE_DELETESAVESCRIPT_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../../../../Engine/Utilities/Globals.hpp"
#include "../../../../../../../Engine/Utilities/EngineCalls.hpp"


using namespace Engine;

class DeleteSaveScript: public Script {
    public:
        DeleteSaveScript(int saveNumber, Script& loadSavesScript, AudioSource& deleteSound, bool active);
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
        // TODO: Store data here temporarily for undo functionality
};


#endif //GOAT_ENGINE_DELETESAVESCRIPT_HPP
