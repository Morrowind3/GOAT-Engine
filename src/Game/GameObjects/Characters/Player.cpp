#include "Player.hpp"
#include "../../Behaviors/PlayerBehavior.hpp"

Player::Player(Transform transform) : GameObject(transform, true) {
    behaviors.push_back(*new PlayerBehavior{*this,true});
    sprites.emplace_back("Goat.png", true);
}