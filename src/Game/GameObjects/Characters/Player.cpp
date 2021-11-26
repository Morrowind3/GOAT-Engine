#include "Player.hpp"
#include "../../Behaviors/Characters/PlayerBehavior.hpp"
#include "../../Keys.hpp"

Player::Player(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<PlayerBehavior>(*this, true)));
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/player/player_idle.png",true}));
    sprites.insert(std::make_pair(Keys::MOVE1, Sprite{"Sprites/player/player_move_1.png", false}));
    sprites.insert(std::make_pair(Keys::JUMP, Sprite{"Sprites/player/player_jump.png", false}));
    audioSources.insert(std::make_pair(Keys::JUMP_SFX,AudioSource{"Sounds/Jump.wav",AudioSourceType::SAMPLE,false,true}));
    audioSources.insert(std::make_pair(Keys::WALK_SFX_A,AudioSource{"Sounds/Walk.ogg",AudioSourceType::SAMPLE,false,true}));
    audioSources.insert(std::make_pair(Keys::WALK_SFX_B,AudioSource{"Sounds/WalkAlt.ogg",AudioSourceType::SAMPLE,false,true}));
}