#include "Behavior_Timer.hpp"
#include "../../../Keys.hpp"
#include "Script_Timer.hpp"

Behavior_Timer::Behavior_Timer(Text& timerText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::TIMER ,std::make_shared<Script_Timer>(timerText, true)));
}
