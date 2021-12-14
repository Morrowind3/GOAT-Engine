#ifndef GOAT_ENGINE_SCRIPT_TIMERLINE_HPP
#define GOAT_ENGINE_SCRIPT_TIMERLINE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_TimerLine.hpp"

using namespace Engine;

class Script_TimerLine : public Script {
public:
    Script_TimerLine(Object_TimerLine& timerLine, double speed, bool active): Script(active), _speed(speed), _timerLine(timerLine){};
    void onUpdate(double deltaTime) override;
private:
    double _speed;
    Object_TimerLine& _timerLine;

};


#endif //GOAT_ENGINE_SCRIPT_TIMERLINE_HPP
