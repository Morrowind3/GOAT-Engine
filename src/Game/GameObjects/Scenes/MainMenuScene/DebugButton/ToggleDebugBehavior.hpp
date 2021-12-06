#ifndef GOAT_ENGINE_TOGGLEDEBUGBEHAVIOR_HPP
#define GOAT_ENGINE_TOGGLEDEBUGBEHAVIOR_HPP


#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"

using namespace Engine;

class ToggleDebugBehavior : public Behavior {
    public: explicit ToggleDebugBehavior(bool active);
};


#endif //GOAT_ENGINE_TOGGLEDEBUGBEHAVIOR_HPP
