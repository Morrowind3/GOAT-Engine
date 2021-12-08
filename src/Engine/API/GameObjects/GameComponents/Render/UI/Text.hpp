#ifndef GOAT_ENGINE_TEXT_HPP
#define GOAT_ENGINE_TEXT_HPP

#include "../../GameComponent.hpp"
#include "../../../Color.hpp"
#include "../../../Transform.hpp"
#include <string>

namespace Engine {
    class Button; // Friend class link
    struct Text : public GameComponent {
        Text(std::string text, std::string font, uint8_t size, Color color, Transform location, bool active);
        std::string text;
        std::string font;
        uint8_t size;
        Color color;
        Transform location;
        private:
            friend class Engine::Button;
            Text(); // Constructor used by buttons when they have no text
    };
}



#endif //GOAT_ENGINE_TEXT_HPP
