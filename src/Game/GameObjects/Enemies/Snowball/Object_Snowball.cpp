#include "Object_Snowball.hpp"
#include "../../../Keys.hpp"
#include "Behavior_Snowball.hpp"

Object_Snowball::Object_Snowball(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/enemies/snowball/snowball.png", true}));
    behaviors.insert(std::make_pair(Keys::SNAKE, std::make_shared<Behavior_Snowball>(*this, true)));
    rigidBody = RigidBody(120.0f, 2.0f, BodyType::DYNAMIC, true);
    collider = CircleCollider(40.0f, 0,0,0, 0.7,false,true);
}
