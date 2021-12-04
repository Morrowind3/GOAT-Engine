#ifndef GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP
#define GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP


#include "HealthPickup.hpp"

class HealthPickupBehavior : public Behavior {
    public: HealthPickupBehavior(HealthPickup& healthPickup, AudioSource& healSfx, bool active);
};


#endif //GOAT_ENGINE_HEALTHPICKUPBEHAVIOR_HPP
