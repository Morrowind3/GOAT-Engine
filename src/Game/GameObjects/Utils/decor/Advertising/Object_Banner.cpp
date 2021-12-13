#include "Object_Banner.hpp"
#include "../../../../Keys.hpp"
#include "Animator_BannerFlutter.hpp"

Object_Banner::Object_Banner(Transform& transform, bool active) : GameObject(transform, active) {
    auto& spriteMain = sprites.insert(std::make_pair(Keys::IDLE,   Sprite{"Sprites/utils/skydecor/airplane_banner.png", true})).first->second;
    auto& spriteAlt = sprites.insert(std::make_pair(Keys::MOVE1, Sprite{"Sprites/utils/skydecor/airplane_banner_wind.png", false})).first->second;

    animators.insert(std::make_pair(Keys::WALKING_ANIMATOR, Animator_BannerFlutter{spriteMain, spriteAlt,true}));
}
