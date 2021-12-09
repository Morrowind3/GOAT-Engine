#include "BackToMenuButton.hpp"
#include "../../../Keys.hpp"
#include "../SwitchSceneButtonBehavior.hpp"

BackToMenuButton::BackToMenuButton(Transform transform, bool active): GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x + 10, transform.position.y + 20},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::MAIN_MENU, Button{
            Text{"Back to menu", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::MAIN_MENU, active),
            true}));

}
