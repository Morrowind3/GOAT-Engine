#include "Snake.hpp"
#include "../../../Keys.hpp"
#include "SnakeBehavior.hpp"

Snake::Snake(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::IDLE, Sprite{"Sprites/enemies/snake/snake_underground.png", true}));
    behaviors.insert(std::make_pair(Keys::SNAKE, std::make_shared<SnakeBehavior>(*this, true)));
    sprites.insert(std::make_pair(Keys::ATTACK1, Sprite{"Sprites/enemies/snake/snake_popup.png", false}));
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
    collider = CircleCollider(10.0f, true,true);
    audioSources.insert(std::make_pair(Keys::BLEATHING, AudioSource{"Sounds/Snake_Hiss.ogg",AudioSourceType::SAMPLE,false,true}));
}
