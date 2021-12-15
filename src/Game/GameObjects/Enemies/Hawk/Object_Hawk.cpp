#include "Object_Hawk.hpp"
#include "Behavior_Hawk.hpp"
#include "../../../Keys.hpp"

Object_Hawk::Object_Hawk(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::MOVE1, Sprite{"Sprites/enemies/bird/bird_idle_1.png", true}));
    sprites.insert(std::make_pair(Keys::MOVE2, Sprite{"Sprites/enemies/bird/bird_idle_2.png", false}));
    sprites.insert(std::make_pair(Keys::ATTACK1, Sprite{"Sprites/enemies/bird/bird_attack.png", false}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Behavior_Hawk>(*this, true)));
    rigidBody = RigidBody(-1, 0, BodyType::DYNAMIC, true);
    collider = CircleCollider(20.0f, 0.0f, 0.0f, 0.2f, 0,false,true);
}