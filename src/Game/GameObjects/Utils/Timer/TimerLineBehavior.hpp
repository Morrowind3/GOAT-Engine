#ifndef GOAT_ENGINE_TIMERLINEBEHAVIOR_HPP
#define GOAT_ENGINE_TIMERLINEBEHAVIOR_HPP
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "TimerLine.hpp"

using namespace Engine;

class TimerLineBehavior : public Behavior {
public: TimerLineBehavior(TimerLine& timerLine, double speed, bool active);
};


#endif //GOAT_ENGINE_TIMERLINEBEHAVIOR_HPP
