#ifndef GOAT_ENGINE_PAUSEACTIVATIONSCRIPT_HPP
#define GOAT_ENGINE_PAUSEACTIVATIONSCRIPT_HPP

#include "../../../../Engine/Utilities/EngineCalls.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class PauseActivationScript : public Script {
    public:
        PauseActivationScript(GameObject& toggleObject, bool activeOnPause, bool active);
        PauseActivationScript(GameComponent& toggleComponent, bool activeOnPause, bool active);
        void onStart();
        void onUpdate(double deltaTime);
    private:
        // Globals
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        GameObject* _toggleObject;
        GameComponent* _toggleComponent;
        bool _activeOnPause;
        // Methods
        void checkPauseState();
};

#endif //GOAT_ENGINE_PAUSEACTIVATIONSCRIPT_HPP
