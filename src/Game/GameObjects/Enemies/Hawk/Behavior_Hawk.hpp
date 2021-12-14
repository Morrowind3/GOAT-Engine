#ifndef GOAT_ENGINE_BEHAVIOR_HAWK_HPP
#define GOAT_ENGINE_BEHAVIOR_HAWK_HPP

#include <memory>

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Script_Hawk.hpp"

using namespace Engine;

class Behavior_Hawk : public Behavior {
    public: Behavior_Hawk(Object_Hawk& self, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_HAWK_HPP
