//
// Created by Stijn van Loon on 16-11-2021.
//

#ifndef GOAT_ENGINE_COLOR_HPP
#define GOAT_ENGINE_COLOR_HPP

#include "SDL.h"

namespace Engine {
    struct Color {
    public:
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0) : color({r, g, b, a}) {}

        SDL_Color get() { return color; }

    private:
        SDL_Color color;

    };
}

#endif //GOAT_ENGINE_COLOR_HPP
