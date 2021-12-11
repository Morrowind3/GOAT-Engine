#include "ToggleDebugBehavior.hpp"
#include "../../../../../Keys.hpp"
#include "DebugToggleScript.hpp"

ToggleDebugBehavior::ToggleDebugBehavior(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SCRIPT,std::make_shared<DebugToggleScript>(true)));
}
