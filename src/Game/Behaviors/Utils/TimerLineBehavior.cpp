//
// Created by Morrowind3 on 03/12/2021.
//

#include "TimerLineBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/TimerLineScript.hpp"

TimerLineBehavior::TimerLineBehavior(TimerLine& timerLine, double speed, bool active) : Behavior(active){
    scripts.insert(std::make_pair(Keys::TIMER, std::make_shared<TimerLineScript>(timerLine, speed, active)));

}
