#include "Hawk.hpp"
#include "../../Behaviors/HawkBehavior.hpp"
#include "../../Keys.hpp"

Hawk::Hawk(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::MOVE1, Sprite{"Sprites/enemies/bird/bird_idle_1.png", true}));
    sprites.insert(std::make_pair(Keys::MOVE2, Sprite{"Sprites/enemies/bird/bird_idle_2.png", false}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<HawkBehaviour>(*this, true)));
}