#ifndef GOAT_ENGINE_ANIMATOR_PLAYERWALKING_HPP
#define GOAT_ENGINE_ANIMATOR_PLAYERWALKING_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class Animator_PlayerWalking : public Animator {
    public: Animator_PlayerWalking(Sprite& move1, Sprite& move2, Sprite& move3, Sprite& move4, bool active);
};

#endif //GOAT_ENGINE_ANIMATOR_PLAYERWALKING_HPP
