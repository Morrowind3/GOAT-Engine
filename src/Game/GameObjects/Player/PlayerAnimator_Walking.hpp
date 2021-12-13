#ifndef GOAT_ENGINE_PLAYERANIMATOR_WALKING_HPP
#define GOAT_ENGINE_PLAYERANIMATOR_WALKING_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class PlayerAnimator_Walking : public Animator {
    public: PlayerAnimator_Walking(Sprite& move1, Sprite& move2, Sprite& move3, Sprite& move4, bool active);
};

#endif //GOAT_ENGINE_PLAYERANIMATOR_WALKING_HPP
