#ifndef GOAT_ENGINE_UIOBJECT_HPP
#define GOAT_ENGINE_UIOBJECT_HPP

#include "Alignment.hpp"
#include "SDL.h"

namespace Engine {
    struct UIObject {
        UIObject(float width, float height, Alignment alignment, SDL_Surface* surface) : width(width), height(height),
                                                                                         alignment(alignment),
                                                                                         surface(surface) {}

        float width;
        float height;
        Alignment alignment;
        SDL_Surface* surface;
    };
}

#endif //GOAT_ENGINE_UIOBJECT_HPP
