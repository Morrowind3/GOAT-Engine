//
// Created by Morrowind3 on 01/12/2021.
//

#ifndef GOAT_ENGINE_TIMERBEHAVIOR_HPP
#define GOAT_ENGINE_TIMERBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"

using namespace Engine;


class TimerBehavior : public Behavior {
    public: TimerBehavior(Text& timerText, bool active);

};


#endif //GOAT_ENGINE_TIMERBEHAVIOR_HPP
