#include "Button.hpp"

using namespace Engine;

Button::Button(Text text, Color backgroundColor, Rectangle dimensions, std::shared_ptr<Behavior> onClick, bool active): GameComponent(active),
        text{std::move(text)}, backgroundColor{backgroundColor}, dimensions{dimensions}, onClick{std::move(onClick)} {
}
