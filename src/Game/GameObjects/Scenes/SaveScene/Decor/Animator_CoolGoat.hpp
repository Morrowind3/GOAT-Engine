#ifndef GOAT_ENGINE_ANIMATOR_COOLGOAT_HPP
#define GOAT_ENGINE_ANIMATOR_COOLGOAT_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class Animator_CoolGoat : public Animator {
    public: Animator_CoolGoat(Sprite& idle1, Sprite& idle2, bool active);
};


#endif //GOAT_ENGINE_ANIMATOR_COOLGOAT_HPP
