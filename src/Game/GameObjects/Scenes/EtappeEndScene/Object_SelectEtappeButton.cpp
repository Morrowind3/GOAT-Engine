#include "Object_SelectEtappeButton.hpp"
#include "../Behavior_SwitchSceneButton.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"

Object_SelectEtappeButton::Object_SelectEtappeButton(Transform transform, bool active) : GameObject(transform, active){
    Transform textTransform{
            Point{transform.position.x + 25, transform.position.y + 40},
            LAYER::UI, 1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::ETAPPE_SELECT, Button{
            Text{" Level Select", "Fonts/Kenney_Thick.ttf", 26, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_outline_white.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 360, 150},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::ETAPPE_SELECT, true),
            true}));
}
