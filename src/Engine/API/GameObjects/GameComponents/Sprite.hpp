#pragma once

#include "GameComponent.hpp"
#include <string>

class Sprite : public GameComponent {
    public:
        Sprite(std::string  sprite, bool active);
        std::string sprite;
};