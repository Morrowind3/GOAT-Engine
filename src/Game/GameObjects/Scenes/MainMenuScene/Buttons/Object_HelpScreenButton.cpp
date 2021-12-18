#include "Object_HelpScreenButton.hpp"
#include "../../../../Keys.hpp"
#include "../../Behavior_SwitchSceneButton.hpp"
#include "../../../../Layers.hpp"

Object_HelpScreenButton::Object_HelpScreenButton(Transform transform, bool active) : GameObject(transform, active) {
    const double widthScale = transform.scaleWidth/6;
    const double heightScale = transform.scaleHeight/4;

    Transform textTransform{
            Point{transform.position.x + (10 * transform.scaleWidth), transform.position.y + (3 * transform.scaleHeight)},
            LAYER::UI, 1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::_, Button{
            Text{"Help", "Fonts/Kenney_Thick.ttf", 36, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_red.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, widthScale*490, heightScale*110},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::HELP_MENU, active),
            true}));
}
