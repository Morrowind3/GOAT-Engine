#include "Animator_BannerFlutter.hpp"

Animator_BannerFlutter::Animator_BannerFlutter(Sprite& stateA, Sprite& stateB, bool active) : Animator(3, true, active) {
    sprites.emplace_back(&stateA);
    sprites.emplace_back(&stateB);
}
