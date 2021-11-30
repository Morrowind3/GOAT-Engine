#include "Text.hpp"

Engine::Text::Text(std::string text, std::string font, uint8_t size, Color color, Transform location, bool active) : GameComponent(active),
    text{std::move(text)}, font{std::move(font)}, color{color}, size{size}, location{location} {
}
