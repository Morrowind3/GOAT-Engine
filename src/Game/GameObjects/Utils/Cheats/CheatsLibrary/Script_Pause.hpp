#ifndef GOAT_ENGINE_SCRIPT_PAUSE_HPP
#define GOAT_ENGINE_SCRIPT_PAUSE_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class Script_Pause : public Script {
    public:
        Script_Pause(AudioSource& pauseSound, bool active);
        void onUpdate(double deltaTime);
        void onExternalEvent();
    private:
        void pauseLogic();
        // Utilities
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        AudioSource& _pauseSound;
};


#endif //GOAT_ENGINE_SCRIPT_PAUSE_HPP
