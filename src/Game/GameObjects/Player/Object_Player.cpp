#include "Object_Player.hpp"
#include "../../Keys.hpp"
#include "Sprites/Sprite_PlayerIdle.hpp"
#include "Sprites/Sprite_PlayerMove1.hpp"
#include "Sprites/Sprite_PlayerMove2.hpp"
#include "Sprites/Sprite_PlayerMove3.hpp"
#include "Sprites/Sprite_PlayerJump.hpp"
#include "Animator_PlayerWalking.hpp"
#include "Sounds/Sound_Jump.hpp"
#include "Sounds/Sound_Walk.hpp"
#include "Sounds/Sound_WalkAlt.hpp"
#include "Sounds/Sound_Oof.hpp"
#include "Sounds/Sound_Death.hpp"
#include "Behavior_Player.hpp"

Object_Player::Object_Player(Transform transform, bool active) : GameObject(transform, active) {
    tags.emplace(Keys::PLAYER, true);
    rigidBody = RigidBody(75.0f, 8.5f, BodyType::DYNAMIC, true);
    collider = OvalCollider(18.5f, 0.8f, 1.55f,0.2f,0, true);
    // Logic
    behaviors.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Behavior_Player>(*this, true)));
    // Render
    auto& idleSprite = sprites.insert(std::make_pair(Keys::IDLE, Sprite_PlayerIdle{false})).first->second;
    auto& moveSprite1 = sprites.insert(std::make_pair(Keys::MOVE1, Sprite_PlayerMove1{false})).first->second;
    auto& moveSprite2 = sprites.insert(std::make_pair(Keys::MOVE2, Sprite_PlayerMove2{false})).first->second;
    auto& moveSprite3 = sprites.insert(std::make_pair(Keys::MOVE3, Sprite_PlayerMove3{false})).first->second;
    auto& jumpSprite = sprites.insert(std::make_pair(Keys::JUMP, Sprite_PlayerJump{false})).first->second;
	auto& pickupSprite = sprites.insert(std::make_pair(Keys::TRASH, Sprite{"Sprites/player/player_pickup.png", false})).first->second;
    animators.insert(std::make_pair(Keys::WALKING_ANIMATOR, Animator_PlayerWalking{moveSprite1, moveSprite2, moveSprite3, moveSprite2, false}));
    // Audio
    audioSources.insert(std::make_pair(Keys::JUMP_SFX,Sound_Jump{1,100,false,true}));
    audioSources.insert(std::make_pair(Keys::WALK_SFX_A,Sound_Walk{1,100,false,true}));
    audioSources.insert(std::make_pair(Keys::WALK_SFX_B,Sound_WalkAlt{1,100,false,true}));
    audioSources.insert(std::make_pair(Keys::DAMAGE_SFX,Sound_Oof{1,100,false,true}));
    audioSources.insert(std::make_pair(Keys::DEATH_SFX,Sound_Death{1,100,false,true}));
}