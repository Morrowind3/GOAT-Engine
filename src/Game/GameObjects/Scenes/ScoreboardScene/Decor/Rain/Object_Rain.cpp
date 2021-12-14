#include "Object_Rain.hpp"
#include "../../../../../Keys.hpp"
#include "Animator_Rain.hpp"

Object_Rain::Object_Rain(Transform transform, bool active) : GameObject(transform, active) {
    auto& rain1 = sprites.insert(std::make_pair(Keys::RAIN, Sprite{"Sprites/backgrounds/rain_foreground/rain_drops-01.png", true})).first->second;
    auto& rain2 = sprites.insert(std::make_pair(Keys::RAIN2, Sprite{"Sprites/backgrounds/rain_foreground/rain_drops-02.png", false})).first->second;
    auto& rain3 = sprites.insert(std::make_pair(Keys::RAIN3, Sprite{"Sprites/backgrounds/rain_foreground/rain_drops-03.png", false})).first->second;
    auto& rain4 = sprites.insert(std::make_pair(Keys::RAIN4, Sprite{"Sprites/backgrounds/rain_foreground/rain_drops-04.png", false})).first->second;
    animators.insert(std::make_pair(Keys::_, Animator_Rain{rain1, rain2, rain3, rain4, true}));
}
