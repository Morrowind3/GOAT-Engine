#include "Animator_PlayerWalking.hpp"

Animator_PlayerWalking::Animator_PlayerWalking(Sprite& move1, Sprite& move2, Sprite& move3, Sprite& move4, bool active):
Animator(6, true, active) {
    sprites.emplace_back(&move1);
    sprites.emplace_back(&move2);
    sprites.emplace_back(&move3);
    sprites.emplace_back(&move4);
}
