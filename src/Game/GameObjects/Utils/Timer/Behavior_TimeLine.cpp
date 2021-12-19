#include "Behavior_TimeLine.hpp"
#include "../../../Keys.hpp"
#include "Script_TimerLine.hpp"

Behavior_TimeLine::Behavior_TimeLine(Object_TimerLine& timerLine, double speed, bool active) : Behavior(active){
    scripts.insert(std::make_pair(Keys::TIMER, std::make_shared<Script_TimerLine>(timerLine, speed, active)));

}
