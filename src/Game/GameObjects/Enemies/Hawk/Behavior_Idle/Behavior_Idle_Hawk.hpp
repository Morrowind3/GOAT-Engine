
#ifndef GOAT_ENGINE_BEHAVIOR_IDLE_HAWK_HPP
#define GOAT_ENGINE_BEHAVIOR_IDLE_HAWK_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Script_Idle_Hawk.hpp"
#include "../Object_Hawk.hpp"

using namespace Engine;

class Behavior_Idle_Hawk : public Behavior {
public: Behavior_Idle_Hawk(Object_Hawk& self, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_IDLE_HAWK_HPP
