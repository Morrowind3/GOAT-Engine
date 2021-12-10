//
// Created by Morrowind3 on 05/12/2021.
//

#include "Trash.hpp"
#include "../../../Keys.hpp"
#include "TrashBehavior.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include <random>
#include <iostream>
#include <chrono>

Trash::Trash(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::TRASH, std::make_shared<TrashBehavior>(*this, true)));
    tags.emplace(Keys::TRASH, true);
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
    collider = BoxCollider(3 * transform.scaleWidth, 3 * transform.scaleHeight, 0,true, true);
    audioSources.insert(std::make_pair(Keys::TRASH, AudioSource{"Sounds/PickUp.ogg", AudioSourceType::SAMPLE, true}));
    Globals::getInstance().gameStore(Keys::TRASH_MAX, Globals::getInstance().gameExists(Keys::TRASH_MAX) ? std::to_string(std::stoi(Globals::getInstance().gameGet(Keys::TRASH_MAX))+1) : "1");

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
    std::uniform_int_distribution<int> random(0,SPRITE_OPTIONS.size()-1);
    sprites.insert(std::make_pair(Keys::TRASH, Sprite{"Sprites/waste/waste_" + SPRITE_OPTIONS[random(generator)] + ".png",true}));
}
