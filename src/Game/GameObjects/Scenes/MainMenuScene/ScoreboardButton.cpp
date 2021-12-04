#include "ScoreboardButton.hpp"
#include "../SwitchSceneButtonBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"

ScoreboardButton::ScoreboardButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 40, transform.position.y + 30},
            LAYER::UI, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Scoreboard", "Fonts/Kenney_Thick.ttf", 16, {0, 0, 0, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/Button_small_white.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, 250, 80},
            std::make_shared<SwitchSceneButtonBehavior>(Keys::SCOREBOARD_MENU, sceneManager, active),
            true}));
};
