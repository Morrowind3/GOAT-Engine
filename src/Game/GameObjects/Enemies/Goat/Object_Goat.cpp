#include "Object_Goat.hpp"
#include "Behavior_Goat.hpp"
#include "../../../Keys.hpp"

Object_Goat::Object_Goat(Object_Player& player, Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/enemies/goat/goat_idle_1.png", true}));
    sprites.insert(std::make_pair(Keys::IDLE2, Sprite{"Sprites/enemies/goat/goat_idle_2.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK_STANCE, Sprite{"Sprites/enemies/goat/goat_attack_stance.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK1, Sprite{"Sprites/enemies/goat/goat_attack_1.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK2, Sprite{"Sprites/enemies/goat/goat_attack_2.png", false}));
    rigidBody = RigidBody(40.0f, 2.0f, BodyType::DYNAMIC, true);
    collider = CircleCollider(42.5f, 0,0, 0.2,false,true);
    behaviors.insert(std::make_pair(Keys::GOAT, std::make_shared<Behavior_Goat>(player, *this, true)));
    audioSources.insert(std::make_pair(Keys::BLEATHING, AudioSource{"Sounds/Bleathing.ogg",AudioSourceType::SAMPLE,80,false,true}));
}
