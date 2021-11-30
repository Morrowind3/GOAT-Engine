//
// Created by Morrowind3 on 29/11/2021.
//

#ifndef GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP
#define GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP


#include "../../GameObjects/WorldObjects/HealthPickup.hpp"

class HealthPickupBehavior : public Behavior {
public: HealthPickupBehavior(HealthPickup& healthPickup, bool active);
};


#endif //GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP
