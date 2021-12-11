#ifndef GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP
#define GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../../Engine/Utilities/Debug.hpp"
#include "../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class SwitchSceneButtonScript : public Script {
    public:
        SwitchSceneButtonScript(std::string levelName, AudioSource* nopeSound, bool active);
        SwitchSceneButtonScript(std::string levelName, bool active);
        void onExternalEvent();
    private:
        // Globals
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        AudioSource* _nopeSound;
        std::string _levelName;
};


#endif //GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP
