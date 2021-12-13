#ifndef GOAT_ENGINE_BEHAVIOR_HEALTHPICKUP_HPP
#define GOAT_ENGINE_BEHAVIOR_HEALTHPICKUP_HPP

#include "Object_HealthPickup.hpp"

class Behavior_HealthPickup : public Behavior {
    public: Behavior_HealthPickup(Object_HealthPickup& healthPickup, AudioSource& healSfx, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_HEALTHPICKUP_HPP
