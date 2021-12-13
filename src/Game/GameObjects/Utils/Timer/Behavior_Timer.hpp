#ifndef GOAT_ENGINE_BEHAVIOR_TIMER_HPP
#define GOAT_ENGINE_BEHAVIOR_TIMER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"

using namespace Engine;


class Behavior_Timer : public Behavior {
    public: Behavior_Timer(Text& timerText, bool active);

};


#endif //GOAT_ENGINE_BEHAVIOR_TIMER_HPP
