#ifndef GOAT_ENGINE_BEHAVIOR_PREDATOR_HAWK_HPP
#define GOAT_ENGINE_BEHAVIOR_PREDATOR_HAWK_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Script_Predator_Hawk.hpp"

using namespace Engine;

class Behavior_Predator_Hawk : public Behavior {
    public: Behavior_Predator_Hawk(Object_Player& player, Object_Hawk& self, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_PREDATOR_HAWK_HPP
