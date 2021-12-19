#ifndef GOAT_ENGINE_SCRIPT_TIMERLINE_HPP
#define GOAT_ENGINE_SCRIPT_TIMERLINE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_TimerLine.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_TimerLine : public Script {
    public:
        Script_TimerLine(Object_TimerLine& timerLine, double speed, bool active);;
        void onStart() override;
        void onUpdate(double deltaTime) override;
    private:
        // Utilities
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        Globals& _globals = Globals::getInstance();
        // Variables
        double _speed;
        Object_TimerLine& _timerLine;
        // Helper methods
        void storePosition();
};


#endif //GOAT_ENGINE_SCRIPT_TIMERLINE_HPP
