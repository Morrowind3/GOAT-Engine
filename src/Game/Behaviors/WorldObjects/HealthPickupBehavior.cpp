#include "HealthPickupBehavior.hpp"
#include "Scripts/HealScript.hpp"
#include "../../Keys.hpp"

HealthPickupBehavior::HealthPickupBehavior(HealthPickup& healthPickup, AudioSource& healSfx, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::JAGERPLEISTER, std::make_shared<HealScript>(healthPickup, healSfx, true )));
}
