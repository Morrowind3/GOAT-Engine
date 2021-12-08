//
// Created by Stijn van Loon on 7-12-2021.
//

#ifndef GOAT_ENGINE_GOATSENSORBEHAVIOR_HPP
#define GOAT_ENGINE_GOATSENSORBEHAVIOR_HPP


#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../GoatBehavior.hpp"

using namespace Engine;

class GoatSensorBehavior : public Behavior {
public: GoatSensorBehavior(GoatBehavior& goat, bool active);
};



#endif //GOAT_ENGINE_GOATSENSORBEHAVIOR_HPP
