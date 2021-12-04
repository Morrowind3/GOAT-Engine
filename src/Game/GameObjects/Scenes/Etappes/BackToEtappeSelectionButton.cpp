#include "BackToEtappeSelectionButton.hpp"
#include "../SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/PauseActivationBehavior.hpp"
#include "../../../Layers.hpp"

BackToEtappeSelectionButton::BackToEtappeSelectionButton(SceneManager& sceneManager, Transform transform, bool active): GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x + 10, transform.position.y + 20},
            LAYER::FPS, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::MAIN_MENU, Button{
            Text{" Leave level", "Fonts/Kenney_Thick.ttf", 16, {0, 0, 0, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::ETAPPE_SELECT, sceneManager, active),
            true}));

    behaviors.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseActivationBehavior>(buttons.at(Keys::MAIN_MENU),true,true)));
}