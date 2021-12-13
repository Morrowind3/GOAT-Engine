#include "Object_AdvertisingPane.hpp"
#include "../../../../Keys.hpp"

Object_AdvertisingPane::Object_AdvertisingPane(Transform transform, bool active) : GameObject(transform,active){
sprites.insert(std::make_pair(Keys::ADVERTISEMENT, Sprite{"Sprites/utils/skydecor/placeholder_advert.png", true}));
tags.insert(std::make_pair(Keys::NO_FLIP, true));
}

