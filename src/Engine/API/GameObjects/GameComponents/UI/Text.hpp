#ifndef GOAT_ENGINE_TEXT_HPP
#define GOAT_ENGINE_TEXT_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {
    struct Text : public GameComponent {
        Text(std::string text, bool active);
        std::string text;
    };
}



#endif //GOAT_ENGINE_TEXT_HPP
