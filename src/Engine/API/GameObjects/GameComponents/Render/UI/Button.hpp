#ifndef GOAT_ENGINE_BUTTON_HPP
#define GOAT_ENGINE_BUTTON_HPP

#include "Text.hpp"
#include "../../Script/Behavior.hpp"
#include "../../../Rectangle.hpp"
#include "../Sprite.hpp"

namespace Engine {
    struct Button : public GameComponent {
        // Button with text
        Button(Text text, Sprite sprite, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active);
        // Button without text
        Button(Sprite sprite, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active);
        Text text;
        Sprite sprite;
        Rectangle dimensions;
        std::shared_ptr<Behavior> onClick;
    };
}

#endif //GOAT_ENGINE_BUTTON_HPP
