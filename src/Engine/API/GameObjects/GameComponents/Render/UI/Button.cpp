#include "Button.hpp"

using namespace Engine;

Button::Button(Text text, Sprite sprite, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active): GameComponent(active),
        text{std::move(text)}, sprite{std::move(sprite)}, dimensions{dimensions}, onClick{std::move(onClick)} {
}

Button::Button(Sprite sprite, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active):
    Button(Text{},std::move(sprite), dimensions,std::move(onClick), active) {
}
