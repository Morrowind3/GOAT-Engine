#ifndef GOAT_ENGINE_TEXT_HPP
#define GOAT_ENGINE_TEXT_HPP

#include "../UIObject.hpp"
#include "../Color.hpp"
#include "SDL_ttf.h"
#include "../Alignment.hpp"

#include <string>

namespace Engine {
    struct Text : UIObject {
        Text(std::string text, const std::string& font, int size, Color color, Alignment alignment);

        std::string text;
        TTF_Font* font;
        Color color;
    };
}

#endif //GOAT_ENGINE_TEXT_HPP