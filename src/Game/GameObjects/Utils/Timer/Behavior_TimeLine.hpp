#ifndef GOAT_ENGINE_BEHAVIOR_TIMELINE_HPP
#define GOAT_ENGINE_BEHAVIOR_TIMELINE_HPP
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_TimerLine.hpp"

using namespace Engine;

class Behavior_TimeLine : public Behavior {
public: Behavior_TimeLine(Object_TimerLine& timerLine, double speed, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_TIMELINE_HPP
