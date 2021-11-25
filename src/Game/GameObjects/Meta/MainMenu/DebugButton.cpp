#include "DebugButton.hpp"
#include "../../../Behaviors/QuitGameBehavior.hpp"
#include "../../../Keys.hpp"

DebugButton::DebugButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 60, transform.position.y + 20},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Debug", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<QuitGameBehavior>(true),
            true}));
};