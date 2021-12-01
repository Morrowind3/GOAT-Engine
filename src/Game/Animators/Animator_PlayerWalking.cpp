#include "Animator_PlayerWalking.hpp"

// TODO: Reduce FPS
Animator_PlayerWalking::Animator_PlayerWalking(Sprite& move1, Sprite& move2, Sprite& move3, bool active): Animator(60,true,active) {
    sprites.emplace_back(&move1);
    sprites.emplace_back(&move2);
    sprites.emplace_back(&move3);
}
