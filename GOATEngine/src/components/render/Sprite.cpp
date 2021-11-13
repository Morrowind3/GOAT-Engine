#include "Sprite.hpp"

using namespace Engine;

Sprite::Sprite(std::string path): _path {std::move(path)} {

}

const std::string& Sprite::path() const {
    return _path;
}
