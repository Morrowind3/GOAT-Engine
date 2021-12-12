//
// Created by Morrowind3 on 11/12/2021.
//

#ifndef GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP
#define GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Render/Animator.hpp"

using namespace Engine;

class Animator_BannerFlutter : public Animator {
public: Animator_BannerFlutter(Sprite& stateA, Sprite& stateB, bool active) : Animator(3, true, active) {
        sprites.emplace_back(&stateA);
        sprites.emplace_back(&stateB);
    };
};


#endif //GOAT_ENGINE_ANIMATOR_BANNERFLUTTER_HPP
