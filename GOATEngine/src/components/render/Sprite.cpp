#include "Sprite.hpp"

#include <utility>

using namespace Engine;

Sprite::Sprite(std::string path): _path {std::move(path)} {

}
