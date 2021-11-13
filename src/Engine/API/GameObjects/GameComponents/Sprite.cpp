#include "Sprite.hpp"

#include <utility>

Sprite::Sprite(std::string sprite, bool active) : GameComponent(GameComponentType::SPRITE, active), sprite{std::move(sprite)}
{
}