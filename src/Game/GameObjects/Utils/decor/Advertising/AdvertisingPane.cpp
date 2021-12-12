//
// Created by Morrowind3 on 10/12/2021.
//

#include "AdvertisingPane.hpp"
#include "../../../../Keys.hpp"
#include "../../../../../Engine/Utilities/Http.hpp"

AdvertisingPane::AdvertisingPane(Transform transform, bool active) : GameObject(transform,active){
sprites.insert(std::make_pair(Keys::ADVERTISEMENT, Sprite{
        Http::getInstance().imageFromWeb("https://i.imgur.com/GbWGjV4.png"), true}));
tags.insert(std::make_pair(Keys::NO_FLIP, true));
}

