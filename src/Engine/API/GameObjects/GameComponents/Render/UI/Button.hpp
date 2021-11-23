#ifndef GOAT_ENGINE_BUTTON_HPP
#define GOAT_ENGINE_BUTTON_HPP

#include "Text.hpp"
#include "../../Script/Behavior.hpp"
#include "../../../Rectangle.hpp"

namespace Engine {
    struct Button : public GameComponent {
        Button(Text text, Color backgroundColor, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active);
        Text text;
        Color backgroundColor;
        Rectangle dimensions;
        std::shared_ptr<Behavior> onClick;
    };
}

#endif //GOAT_ENGINE_BUTTON_HPP
