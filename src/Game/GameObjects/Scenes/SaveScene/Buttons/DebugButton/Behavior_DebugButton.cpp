#include "Behavior_DebugButton.hpp"
#include "../../../../../Keys.hpp"
#include "Script_DebugToggle.hpp"

Behavior_DebugButton::Behavior_DebugButton(AudioSource& enableSound, AudioSource& disableSound, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SCRIPT,std::make_shared<Script_DebugToggle>(enableSound,disableSound,true)));
}
