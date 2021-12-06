#include "Snowball.hpp"
#include "../../../Keys.hpp"
#include "SnowballBehavior.hpp"

Snowball::Snowball(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/enemies/snowball/snowball.png", true}));
    behaviors.insert(std::make_pair(Keys::SNAKE, std::make_shared<SnowballBehavior>(*this, true)));
    rigidBody = RigidBody(120.0f, 2.0f, BodyType::DYNAMIC, true);
    collider = CircleCollider(40.0f, false,true);
}
