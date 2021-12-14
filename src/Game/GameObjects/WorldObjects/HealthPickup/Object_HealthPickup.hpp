#ifndef GOAT_ENGINE_OBJECT_HEALTHPICKUP_HPP
#define GOAT_ENGINE_OBJECT_HEALTHPICKUP_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_HealthPickup : public GameObject {
    public: Object_HealthPickup(Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_HEALTHPICKUP_HPP
