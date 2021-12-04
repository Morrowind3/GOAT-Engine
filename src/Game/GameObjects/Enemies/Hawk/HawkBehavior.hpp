#ifndef GOAT_ENGINE_HAWKBEHAVIOR_HPP
#define GOAT_ENGINE_HAWKBEHAVIOR_HPP

#include <memory>

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "HawkScript.hpp"

using namespace Engine;

class HawkBehaviour : public Behavior {
    public: HawkBehaviour(Hawk& self, bool active);
};


#endif //GOAT_ENGINE_HAWKBEHAVIOR_HPP
