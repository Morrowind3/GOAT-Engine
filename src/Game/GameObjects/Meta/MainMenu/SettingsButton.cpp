#include "SettingsButton.hpp"
#include "../../../Behaviors/SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"

SettingsButton::SettingsButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 40, transform.position.y + 25},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Settings", "Fonts/Kenney_Thick.ttf", 12, {0, 0, 0, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_white.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::SETTINGS_MENU, sceneManager, active),
            true}));
};
