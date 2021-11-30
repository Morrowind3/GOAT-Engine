//
// Created by Morrowind3 on 29/11/2021.
//

#include "HealthPickupBehavior.hpp"
#include "Scripts/HealScript.hpp"
#include "../../Keys.hpp"


HealthPickupBehavior::HealthPickupBehavior(HealthPickup& healthPickup, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::JAGERPLEISTER , std::make_shared<HealScript>(healthPickup, true )));
}
