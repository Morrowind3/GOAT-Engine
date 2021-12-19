#include "Object_BackToMenuButton.hpp"
#include "../../../Keys.hpp"
#include "../Behavior_SwitchSceneButton.hpp"

Object_BackToMenuButton::Object_BackToMenuButton(Transform transform, bool active): GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x + 10, transform.position.y + 20},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 0.25*transform.scaleWidth, 0.25*transform.scaleHeight};

    buttons.insert(std::make_pair(Keys::MAIN_MENU, Button{
            Text{"Back to menu", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 50*transform.scaleWidth, 20*transform.scaleHeight},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::MAIN_MENU, active),
            true}));

}
