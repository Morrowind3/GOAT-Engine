#ifndef GOAT_ENGINE_BEHAVIOR_SNOWBALL_HPP
#define GOAT_ENGINE_BEHAVIOR_SNOWBALL_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Snowball.hpp"

using namespace Engine;

class Behavior_Snowball : public Behavior {
public:
    Behavior_Snowball(Object_Snowball& snowball, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_SNOWBALL_HPP
