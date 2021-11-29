#include "NextEtappeButton.hpp"
#include "../../../Keys.hpp"
#include "../../../Behaviors/Buttons/SwitchSceneButtonBehavior.hpp"
#include "../../../Layers.hpp"

NextEtappeButton::NextEtappeButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {
    Transform textTransform{
            Point{transform.position.x + 95, transform.position.y + 40},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::NEXT_ETAPPE, Button{
            Text{"Next", "Fonts/Kenney_Thick.ttf", 35, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_outline_white.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::NEXT_ETAPPE, sceneManager, true),
            true}));
}
