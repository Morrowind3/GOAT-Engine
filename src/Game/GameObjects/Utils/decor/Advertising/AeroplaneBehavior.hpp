//
// Created by Morrowind3 on 11/12/2021.
//

#ifndef GOAT_ENGINE_AEROPLANEBEHAVIOR_HPP
#define GOAT_ENGINE_AEROPLANEBEHAVIOR_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Aeroplane.hpp"

using namespace Engine;

class AeroplaneBehavior : public Behavior {
    public: AeroplaneBehavior(Aeroplane& plane, bool active);

};


#endif //GOAT_ENGINE_AEROPLANEBEHAVIOR_HPP
