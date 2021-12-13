#include "Behavior_HealthPickup.hpp"
#include "Script_Heal.hpp"
#include "../../../Keys.hpp"

Behavior_HealthPickup::Behavior_HealthPickup(Object_HealthPickup& healthPickup, AudioSource& healSfx, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::JAGERPLEISTER, std::make_shared<Script_Heal>(healthPickup, healSfx, true )));
}
