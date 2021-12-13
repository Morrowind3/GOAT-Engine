#ifndef GOAT_ENGINE_SCRIPT_SWITCHSCENEBUTTON_HPP
#define GOAT_ENGINE_SCRIPT_SWITCHSCENEBUTTON_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../../Engine/Utilities/Debug.hpp"
#include "../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_SwitchSceneButton : public Script {
    public:
        Script_SwitchSceneButton(std::string levelName, AudioSource* nopeSound, bool active);
        Script_SwitchSceneButton(std::string levelName, bool active);
        void onExternalEvent();
    private:
        // Globals
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        AudioSource* _nopeSound;
        std::string _levelName;
};


#endif //GOAT_ENGINE_SCRIPT_SWITCHSCENEBUTTON_HPP
