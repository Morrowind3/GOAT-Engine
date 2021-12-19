#include "Behavior_Idle_Hawk.hpp"
#include "../../../../Keys.hpp"

// Expected behavior:
// - flies circles in the air

Behavior_Idle_Hawk::Behavior_Idle_Hawk(Object_Hawk& self, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::HAWK,std::make_shared<Script_Idle_Hawk>(self, true)));
}