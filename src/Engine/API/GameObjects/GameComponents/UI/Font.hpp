//
// Created by Stijn van Loon on 17-11-2021.
//

#ifndef GOAT_ENGINE_FONT_HPP
#define GOAT_ENGINE_FONT_HPP

#include "../GameComponent.hpp"
#include <string>
#include <SDL.h>

namespace Engine {
    struct Font : public GameComponent {
        Font(std::string name, std::string path, Uint8 size, bool active);
        std::string name;
        std::string path;
        Uint8 size;
    };
}

#endif //GOAT_ENGINE_FONT_HPP
