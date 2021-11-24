//
// Created by Stijn van Loon on 24-11-2021.
//

#ifndef GOAT_ENGINE_HAWKBEHAVIOR_HPP
#define GOAT_ENGINE_HAWKBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/HawkScript.hpp"

using namespace Engine;

class HawkBehaviour : public Behavior {
public:
    HawkBehaviour(Hawk& self, bool active) : Behavior(active) {
        scripts.emplace_back(std::make_shared<HawkScript>(self, true));
    }
};


#endif //GOAT_ENGINE_HAWKBEHAVIOR_HPP
