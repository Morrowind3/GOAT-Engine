#include "Text.hpp"

using namespace Engine;

Text::Text(std::string text, std::string font, TextAlignment alignment, uint8_t size, Color color, Transform location, bool active) : GameComponent(active),
    text{std::move(text)}, font{std::move(font)}, alignment{alignment}, color{color}, size{size}, location{location} {
}

Text::Text(std::string text, std::string font, uint8_t size, Color color, Transform location, bool active):
        Text(std::move(text), std::move(font), TextAlignment::LEFT, size, color, location, active) {
}

Text::Text(): Text({},{},0,{},Transform{{}},false) {
}
