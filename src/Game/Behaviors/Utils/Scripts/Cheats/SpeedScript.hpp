#ifndef GOAT_ENGINE_SPEEDSCRIPT_HPP
#define GOAT_ENGINE_SPEEDSCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class SpeedScript : public Script {
    public:
        SpeedScript(AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSound,
                    AudioSource& impossibleToAdjustSound, bool active);
        void onUpdate(double deltaTime);
    private:
        void speedUp();
        void slowDown();
        void resetSpeed();
        // Utilities
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        AudioSource& _speedUpSound,& _slowDownSound,& _resetSound,& _impossibleToAdjustSound;
        // Constants
        const double MAX_SPEED = 3.0, MIN_SPEED = 1.0/MAX_SPEED, SPEED_TICK = MAX_SPEED/10.0;
};


#endif //GOAT_ENGINE_SPEEDSCRIPT_HPP
