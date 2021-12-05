//
// Created by Morrowind3 on 05/12/2021.
//

#include "Trash.hpp"
#include "../../../Keys.hpp"
#include <random>
#include <iostream>
#include <chrono>

Trash::Trash(Transform transform, bool active) : GameObject(transform, active) {
    const static std::vector<std::string> SPRITE_OPTIONS = {
        "aluminiumcan",
        "beerbottle",
        "bottle",
        "chemical",
        "liquorbottle",
        "mug",
        "paintcan",
        "pizzabox",
        "sac",
        "tincan",
        "tunacan",
        "waterbottle"
    };

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> random(0,SPRITE_OPTIONS.size());



    std::cout << "Sprites/utils/waste/waste_" + SPRITE_OPTIONS[random(generator)] + ".png" <<  std::endl;
    sprites.insert(std::make_pair(Keys::TRASH, Sprite{"Sprites/waste/waste_" + SPRITE_OPTIONS[random(generator)] + ".png",true}));
}
