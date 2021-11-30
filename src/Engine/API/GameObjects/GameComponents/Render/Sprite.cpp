#include "Sprite.hpp"

using namespace Engine;

Sprite::Sprite(std::string path, bool active) : GameComponent(active), path{std::move(path)} {
}
