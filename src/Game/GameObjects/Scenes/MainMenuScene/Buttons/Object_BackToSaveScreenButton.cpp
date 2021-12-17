#include "Object_BackToSaveScreenButton.hpp"
#include "../../../../Keys.hpp"
#include "../../Behavior_SwitchSceneButton.hpp"

Object_BackToSaveScreenButton::Object_BackToSaveScreenButton(Transform transform, bool active) : GameObject(transform, active) {

    const double widthScale = transform.scaleWidth/6;
    const double heightScale = transform.scaleHeight/4;

    Transform textTransform{
            Point{transform.position.x + 2 +(widthScale * 5 * transform.scaleWidth), transform.position.y + (6 * transform.scaleHeight)},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::_, Button{
            Text{"Return to save menu", "Fonts/Kenney_Thick.ttf", static_cast<uint8_t>(heightScale*24), {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, widthScale*490, heightScale*110},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::SAVE_MENU, active),
            true}));

}
