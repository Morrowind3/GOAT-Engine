#ifndef GOAT_ENGINE_TIMERLINESCRIPT_HPP
#define GOAT_ENGINE_TIMERLINESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "TimerLine.hpp"

using namespace Engine;

class TimerLineScript : public Script {
public:
    TimerLineScript(TimerLine& timerLine, double speed, bool active): Script(active), _speed(speed), _timerLine(timerLine){};
    void onUpdate(double deltaTime) override;
private:
    double _speed;
    TimerLine& _timerLine;

};


#endif //GOAT_ENGINE_TIMERLINESCRIPT_HPP
