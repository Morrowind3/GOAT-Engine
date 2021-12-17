#include "Animator_Rain.hpp"

Animator_Rain::Animator_Rain(Sprite& rain1, Sprite& rain2, Sprite& rain3, Sprite& rain4, bool active):
Animator(4, true, active) {
    sprites.emplace_back(&rain1);
    sprites.emplace_back(&rain2);
    sprites.emplace_back(&rain3);
    sprites.emplace_back(&rain4);
}
