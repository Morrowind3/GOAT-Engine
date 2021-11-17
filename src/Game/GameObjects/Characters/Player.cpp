#include "Player.hpp"
#include "../../Behaviors/PlayerBehavior.hpp"

Player::Player(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.push_back(*new PlayerBehavior{*this,true});
    sprites.insert(std::make_pair(PLAYER::IDLE, Sprite{"Sprites/player/player_idle.png",true}));
    sprites.insert(std::make_pair(PLAYER::MOVE1, Sprite{"Sprites/player/player_move_1.png", false}));
    text.insert(std::make_pair(PLAYER::TEST_TEXT, Text{"Mount Everestimate","Fonts/Kenney_Thick.ttf",16,{0,0,0,255},Transform{{300,300},300},true}));
}