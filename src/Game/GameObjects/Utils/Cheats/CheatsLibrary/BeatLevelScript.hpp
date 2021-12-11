#ifndef GOAT_ENGINE_BEATLEVELSCRIPT_HPP
#define GOAT_ENGINE_BEATLEVELSCRIPT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"

using namespace Engine;

class BeatLevelScript : public Script {
    public:
        BeatLevelScript(AudioSource& beatGameSfx, bool active);
        // TODO: OnInit when script system supports it properly
        void onUpdate(double deltaTime);
    private:
        // Globals
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        Input& _input = Input::getInstance();
        // Variables
        AudioSource& _beatGameSfx;
        double _activationTimer{0.0};
        bool _activated{false};
        // Consts
        const double BEAT_GAME_SFX_DURATION = 1131.0;
};


#endif //GOAT_ENGINE_BEATLEVELSCRIPT_HPP
