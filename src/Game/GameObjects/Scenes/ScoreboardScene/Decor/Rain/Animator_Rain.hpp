#ifndef GOAT_ENGINE_ANIMATOR_RAIN_HPP
#define GOAT_ENGINE_ANIMATOR_RAIN_HPP

#include "../../../../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class Animator_Rain: public Animator {
    public: Animator_Rain(Sprite& rain1, Sprite& rain2, Sprite& rain3, Sprite& rain4, bool active);
};

#endif //GOAT_ENGINE_ANIMATOR_RAIN_HPP
