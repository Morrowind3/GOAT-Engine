#ifndef GOAT_ENGINE_BEHAVIOR_VICTORYFLAG_HPP
#define GOAT_ENGINE_BEHAVIOR_VICTORYFLAG_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "Object_VictoryFlag.hpp"

using namespace Engine;

class Behavior_VictoryFlag : public Behavior {
    public: Behavior_VictoryFlag(Object_VictoryFlag& flag, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_VICTORYFLAG_HPP
