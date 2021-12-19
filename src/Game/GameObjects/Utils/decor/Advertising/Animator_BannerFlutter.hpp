#ifndef GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP
#define GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class Animator_BannerFlutter : public Animator {
    public: Animator_BannerFlutter(Sprite& stateA, Sprite& stateB, bool active);
};

#endif //GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP
