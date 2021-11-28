#ifndef GOAT_ENGINE_PAUSESCRIPT_HPP
#define GOAT_ENGINE_PAUSESCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class PauseScript : public Script {
    public:
        PauseScript(AudioSource& pauseSound, bool active);
        void onStart();
        void onUpdate(double deltaTime);
        void onExternalEvent();
        void onDestroy();

    private:
        void pauseLogic();
        // Utilities
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        Globals& _globals = Globals::getInstance();
        // Variables
        bool _isPaused = false; // Quick access bool
        AudioSource& _pauseSound;
};


#endif //GOAT_ENGINE_PAUSESCRIPT_HPP
