#ifndef GOAT_ENGINE_BEHAVIOR_FPSMETER_HPP
#define GOAT_ENGINE_BEHAVIOR_FPSMETER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Behavior_FpsMeter : public Behavior {
    public: Behavior_FpsMeter(Text& fpsText, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_FPSMETER_HPP
