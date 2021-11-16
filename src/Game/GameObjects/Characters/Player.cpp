#include "Player.hpp"
#include "../../Behaviors/PlayerBehavior.hpp"

Player::Player(Transform transform) : GameObject(transform, true) {
    behaviors.push_back(*new PlayerBehavior{*this,true});
    sprites.insert(std::make_pair(PLAYER::IDLE, Sprite{"Sprites/player/player_idle.png",true}));
    sprites.insert(std::make_pair(PLAYER::MOVE1, Sprite{"Sprites/player/player_move_1.png", true}));
    activeSprite = &sprites.at(PLAYER::IDLE);
}