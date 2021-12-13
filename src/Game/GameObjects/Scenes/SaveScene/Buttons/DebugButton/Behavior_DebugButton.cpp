#include "Behavior_DebugButton.hpp"
#include "../../../../../Keys.hpp"
#include "Script_DebugToggle.hpp"

Behavior_DebugButton::Behavior_DebugButton(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SCRIPT,std::make_shared<Script_DebugToggle>(true)));
}
