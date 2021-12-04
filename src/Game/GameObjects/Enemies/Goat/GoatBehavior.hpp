#ifndef GOAT_ENGINE_GOATBEHAVIOR_HPP
#define GOAT_ENGINE_GOATBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Goat.hpp"

using namespace Engine;

class GoatBehavior : public Behavior {
    public: GoatBehavior(Goat& goat, bool active);
};

#endif //GOAT_ENGINE_GOATBEHAVIOR_HPP