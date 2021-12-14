#include "Object_AdvertisingPane.hpp"
#include "../../../../Keys.hpp"
#include "../../../../../Engine/Utilities/Http.hpp"
#include <random>
#include <chrono>
#include <iostream>

Object_AdvertisingPane::Object_AdvertisingPane(Transform transform, bool active) : GameObject(transform,active){
    std::vector<std::string> adverts = {
            "https://i.imgur.com/GbWGjV4.png",
            "https://i.imgur.com/vzsq2CS.jpg",
            "https://i.imgur.com/4GARU2X.jpg"
    };

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_int_distribution<int> dist(0, adverts.size());
    std::default_random_engine random(seed);

    std::string advert = adverts[dist(random)];
    std::cout << advert <<std::endl;

sprites.insert(std::make_pair(Keys::ADVERTISEMENT, Sprite{
        Http::getInstance().imageFromWeb(advert), true}));
tags.insert(std::make_pair(Keys::NO_FLIP, true));
}

