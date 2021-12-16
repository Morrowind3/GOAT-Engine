#include "Object_CreditsButton.hpp"
#include "../../Behavior_SwitchSceneButton.hpp"
#include "../../../../Keys.hpp"
#include "../../../../Layers.hpp"

Object_CreditsButton::Object_CreditsButton(Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + (20 * transform.scaleWidth), transform.position.y + (5 * transform.scaleHeight)},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::_, Button{
            Text{"Credits", "Fonts/Kenney_Thick.ttf", 24, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, 400, 90},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::CREDITS_MENU, active),
            true}));
};
