#include "PlayerAnimator_Walking.hpp"

PlayerAnimator_Walking::PlayerAnimator_Walking(Sprite& move1, Sprite& move2, Sprite& move3, Sprite& move4, bool active):
Animator(6, true, active) {
    sprites.emplace_back(&move1);
    sprites.emplace_back(&move2);
    sprites.emplace_back(&move3);
    sprites.emplace_back(&move4);
}
