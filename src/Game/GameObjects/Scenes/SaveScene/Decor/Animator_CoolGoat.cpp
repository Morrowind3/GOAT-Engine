#include "Animator_CoolGoat.hpp"

Animator_CoolGoat::Animator_CoolGoat(Sprite& idle1, Sprite& idle2, bool active):
Animator(3, true, active) {
    sprites.emplace_back(&idle1);
    sprites.emplace_back(&idle2);
}
