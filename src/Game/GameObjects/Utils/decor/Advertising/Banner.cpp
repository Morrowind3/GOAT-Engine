//
// Created by Morrowind3 on 10/12/2021.
//

#include "Banner.hpp"
#include "../../../../Keys.hpp"

Banner::Banner(Transform& transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::BANNER, Sprite{"Sprites/utils/skydecor/airplane_banner.png", true}));
    sprites.insert(std::make_pair(Keys::ANIMATOR, Sprite{"Sprites/utils/skydecor/airplane_banner_wind.png", false}));

}
