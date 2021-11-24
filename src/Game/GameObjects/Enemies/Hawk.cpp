//
// Created by Stijn van Loon on 24-11-2021.
//

#include "Hawk.hpp"
#include "../../Behaviors/HawkBehavior.hpp"

Hawk::Hawk(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(HAWK::MOVE1, Sprite{"Sprites/enemies/bird/bird_idle_1.png", true}));
    sprites.insert(std::make_pair(HAWK::MOVE2, Sprite{"Sprites/enemies/bird/bird_idle_2.png", false}));
    behaviors.push_back(std::make_shared<HawkBehaviour>(*this, true));
}