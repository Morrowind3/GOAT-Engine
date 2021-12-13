#ifndef GOAT_ENGINE_TRASHANIMATOR_HPP
#define GOAT_ENGINE_TRASHANIMATOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class TrashAnimator: public Animator {
    public: TrashAnimator(Sprite& trash0, Sprite& trash1, Sprite& trash2, Sprite& trash3, bool active);
};


#endif //GOAT_ENGINE_TRASHANIMATOR_HPP
