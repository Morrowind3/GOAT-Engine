#include "Player.hpp"
#include "../../Behaviors/PlayerBehavior.hpp"

Player::Player(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.push_back(std::make_shared<PlayerBehavior>(*this, true));
    rigidBody = RigidBody(5.0f, 3.5f, BodyType::DYNAMIC, true);
    collider = BoxCollider(105,105, true);
    sprites.insert(std::make_pair(PLAYER::IDLE, Sprite{"Sprites/player/player_idle.png",true}));
    sprites.insert(std::make_pair(PLAYER::MOVE1, Sprite{"Sprites/player/player_move_1.png", false}));
    sprites.insert(std::make_pair(PLAYER::JUMP, Sprite{"Sprites/player/player_jump.png", false}));
    audioSources.insert(std::make_pair(PLAYER::JUMP_SFX,AudioSource{"Sounds/Jump.wav",AudioSourceType::SAMPLE,false,true}));
    audioSources.insert(std::make_pair(PLAYER::WALK_SFX_A,AudioSource{"Sounds/Walk.ogg",AudioSourceType::SAMPLE,false,true}));
    audioSources.insert(std::make_pair(PLAYER::WALK_SFX_B,AudioSource{"Sounds/WalkAlt.ogg",AudioSourceType::SAMPLE,false,true}));
    text.insert(std::make_pair(PLAYER::TEST_TEXT, Text{"Mount Everestimate","Fonts/Kenney_Thick.ttf",16,{0,0,0,255},Transform{{0,0},300,0,6,6},true}));
}