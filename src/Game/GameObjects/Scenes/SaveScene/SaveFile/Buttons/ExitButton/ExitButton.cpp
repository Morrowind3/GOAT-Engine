#include "ExitButton.hpp"
#include "QuitGameBehavior.hpp"
#include "../../../../../../Keys.hpp"

ExitButton::ExitButton(Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 35, transform.position.y + 15},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 2, 2};

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Exit", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_small_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<QuitGameBehavior>(true),
            true}));
};
