#ifndef GOAT_ENGINE_BEHAVIOR_AEROPLANE_HPP
#define GOAT_ENGINE_BEHAVIOR_AEROPLANE_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Aeroplane.hpp"

using namespace Engine;

class Behavior_Aeroplane : public Behavior {
    public: Behavior_Aeroplane(Object_Aeroplane& plane, bool active);

};


#endif //GOAT_ENGINE_BEHAVIOR_AEROPLANE_HPP
