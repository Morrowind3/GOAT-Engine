#include "BackToEtappeSelectionButton.hpp"
#include "../SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/PauseActivationBehavior.hpp"

BackToEtappeSelectionButton::BackToEtappeSelectionButton(Transform transform, bool active): GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x + 25, transform.position.y + 15},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::MAIN_MENU, Button{
            Text{" Leave level", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::ETAPPE_SELECT, active),
            true}));

    behaviors.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseActivationBehavior>(buttons.at(Keys::MAIN_MENU),true,true)));
}
