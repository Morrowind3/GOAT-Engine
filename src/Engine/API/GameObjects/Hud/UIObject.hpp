#ifndef GOAT_ENGINE_UIOBJECT_HPP
#define GOAT_ENGINE_UIOBJECT_HPP

#include "Alignment.hpp"

namespace Engine {
    struct UIObject {
        UIObject(float width, float height, Alignment alignment) : width(width), height(height), alignment(alignment) {}
        float width;
        float height;
        Alignment alignment;
    };
}

#endif //GOAT_ENGINE_UIOBJECT_HPP
