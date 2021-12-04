#include "TimerLineBehavior.hpp"
#include "../../../Keys.hpp"
#include "TimerLineScript.hpp"

TimerLineBehavior::TimerLineBehavior(TimerLine& timerLine, double speed, bool active) : Behavior(active){
    scripts.insert(std::make_pair(Keys::TIMER, std::make_shared<TimerLineScript>(timerLine, speed, active)));

}
