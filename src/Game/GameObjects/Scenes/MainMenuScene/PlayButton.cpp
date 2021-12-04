#include "PlayButton.hpp"
#include "../SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"

PlayButton::PlayButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + (10 * transform.scaleWidth), transform.position.y + (12 * transform.scaleHeight)},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Play", "Fonts/Kenney_Thick.ttf", 36, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_large_blue.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, 250, 160},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::ETAPPE_SELECT, sceneManager, active),
            true}));
};
