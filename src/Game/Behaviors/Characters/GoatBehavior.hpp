//
// Created by Morrowind3 on 28/11/2021.
//

#ifndef GOAT_ENGINE_GOATBEHAVIOR_HPP
#define GOAT_ENGINE_GOATBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../GameObjects/Enemies/Goat.hpp"

using namespace Engine;

class GoatBehavior : public Behavior {
public: GoatBehavior(Goat& goat, bool active);
};


#endif //GOAT_ENGINE_GOATBEHAVIOR_HPP
