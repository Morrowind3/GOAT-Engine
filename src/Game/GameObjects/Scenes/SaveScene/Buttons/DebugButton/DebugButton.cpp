#include "DebugButton.hpp"
#include "../../../../../Keys.hpp"
#include "../../../../../Layers.hpp"
#include "ToggleDebugBehavior.hpp"

DebugButton::DebugButton(Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 50, transform.position.y + 20},
            LAYER::UI, 1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Toggle logging", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 325, 65},
            std::make_shared<ToggleDebugBehavior>(true),
            true}));

}