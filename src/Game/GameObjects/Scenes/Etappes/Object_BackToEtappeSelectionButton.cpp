#include "Object_BackToEtappeSelectionButton.hpp"
#include "../Behavior_SwitchSceneButton.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/Behavior_PauseActivation.hpp"

Object_BackToEtappeSelectionButton::Object_BackToEtappeSelectionButton(Transform transform, bool active): GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x + 25, transform.position.y + 15},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::MAIN_MENU, Button{
            Text{" Leave level", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::ETAPPE_SELECT, active),
            true}));

    behaviors.insert(std::make_pair(Keys::PAUSE, std::make_shared<Behavior_PauseActivation>(buttons.at(Keys::MAIN_MENU),true,true)));
}
