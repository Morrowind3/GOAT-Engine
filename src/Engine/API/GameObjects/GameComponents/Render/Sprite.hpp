#ifndef GOAT_ENGINE_SPRITE_HPP
#define GOAT_ENGINE_SPRITE_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    struct Sprite : public GameComponent {
        Sprite(std::string path, bool active);
        std::string path;
    };
}

#endif //GOAT_ENGINE_SPRITE_HPP
