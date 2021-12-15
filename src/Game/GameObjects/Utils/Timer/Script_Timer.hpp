#ifndef GOAT_ENGINE_SCRIPT_TIMER_HPP
#define GOAT_ENGINE_SCRIPT_TIMER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/Utilities/Clock.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_Timer : public Script {
    public:
        Script_Timer(Text& timerText, bool active);
        void onUpdate(double deltaTime) override; // Timer tick
    private:
        // Utilities
        Globals& _globals = Globals::getInstance();
        Clock& _clock = Clock::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        Text& _text;
        double _totalMs = 0;
        int _totalSeconds = 0;
        // Helper methods
        void addSecond();
        void storeState();
};


#endif //GOAT_ENGINE_SCRIPT_TIMER_HPP
