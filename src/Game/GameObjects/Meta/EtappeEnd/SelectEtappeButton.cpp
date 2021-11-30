#include "SelectEtappeButton.hpp"
#include "../../../Behaviors/Buttons/SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"

SelectEtappeButton::SelectEtappeButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active){
    Transform textTransform{
            Point{transform.position.x + 25, transform.position.y + 40},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::ETAPPE_SELECT, Button{
            Text{" Level Select", "Fonts/Kenney_Thick.ttf", 26, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_outline_white.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::ETAPPE_SELECT, sceneManager, true),
            true}));
}
