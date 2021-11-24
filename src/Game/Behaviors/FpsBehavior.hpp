#ifndef GOAT_ENGINE_FPSBEHAVIOR_HPP
#define GOAT_ENGINE_FPSBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class FpsBehavior : public Behavior {
    public: FpsBehavior(Text& fpsText, bool active);
};


#endif //GOAT_ENGINE_FPSBEHAVIOR_HPP
