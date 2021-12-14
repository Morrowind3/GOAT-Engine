#include "Object_ScoreboardButton.hpp"
#include "../../Behavior_SwitchSceneButton.hpp"
#include "../../../../Keys.hpp"

Object_ScoreboardButton::Object_ScoreboardButton(Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 55, transform.position.y + 20},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::SCOREBOARD_MENU, Button{
            Text{"Scoreboard", "Fonts/Kenney_Thick.ttf", 20, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{Point{transform.position.x, transform.position.y}, 325, 65},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::SCOREBOARD_MENU, active),
            true}));
};
