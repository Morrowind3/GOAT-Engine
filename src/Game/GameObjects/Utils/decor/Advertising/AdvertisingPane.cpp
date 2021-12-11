//
// Created by Morrowind3 on 10/12/2021.
//

#include "AdvertisingPane.hpp"
#include "../../../../Keys.hpp"

AdvertisingPane::AdvertisingPane(Transform transform, bool active) : GameObject(transform,active){
sprites.insert(std::make_pair(Keys::ADVERTISEMENT, Sprite{"Sprites/utils/skydecor/placeholder_advert.png", true}));
tags.insert(std::make_pair(Keys::NO_FLIP, true));
}

