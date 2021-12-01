//
// Created by Morrowind3 on 01/12/2021.
//

#include "TimerBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/TimerScript.hpp"

TimerBehavior::TimerBehavior(Text& timerText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TIMER ,std::make_shared<TimerScript>(timerText, true)));
}
