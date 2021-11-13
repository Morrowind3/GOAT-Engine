#pragma once

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    struct Sprite : public GameComponent {
        Sprite(std::string path, bool active);
        std::string path;
    };
}
