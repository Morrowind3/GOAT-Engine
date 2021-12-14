#ifndef GOAT_ENGINE_BEHAVIOR_GOAT_HPP
#define GOAT_ENGINE_BEHAVIOR_GOAT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Goat.hpp"

using namespace Engine;

class Behavior_Goat : public Behavior {
    public: Behavior_Goat(Object_Player& player, Object_Goat& goat, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_GOAT_HPP
