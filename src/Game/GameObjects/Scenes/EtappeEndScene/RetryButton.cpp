#include "RetryButton.hpp"
#include "../../../Keys.hpp"
#include "../SwitchSceneButtonBehavior.hpp"
#include "../../../Layers.hpp"

RetryButton::RetryButton(Transform transform, bool active) : GameObject(transform, active)  {
    Transform textTransform{
            Point{transform.position.x + 40, transform.position.y + 40},
            LAYER::UI, 1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::CURRENT_ETAPPE, Button{
            Text{"   Try Again", "Fonts/Kenney_Thick.ttf", 26, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_outline_white.png", active},
            Rectangle{{transform.position.x+30, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::CURRENT_ETAPPE, true),
            true}));
}
