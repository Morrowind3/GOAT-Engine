#ifndef GOAT_ENGINE_SNOWBALLBEHAVIOR_HPP
#define GOAT_ENGINE_SNOWBALLBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Snowball.hpp"

using namespace Engine;

class SnowballBehavior : public Behavior {
public:
    SnowballBehavior(Snowball& snowball, bool active);
};


#endif //GOAT_ENGINE_SNOWBALLBEHAVIOR_HPP
