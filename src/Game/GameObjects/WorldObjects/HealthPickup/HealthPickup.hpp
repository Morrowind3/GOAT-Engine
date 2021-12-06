#ifndef GOAT_ENGINE_HEALTHPICKUP_HPP
#define GOAT_ENGINE_HEALTHPICKUP_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class HealthPickup : public GameObject {
    public: HealthPickup(Transform transform, bool active);
};


#endif //GOAT_ENGINE_HEALTHPICKUP_HPP
