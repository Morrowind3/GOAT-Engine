#ifndef GOAT_ENGINE_EXITBUTTON_HPP
#define GOAT_ENGINE_EXITBUTTON_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Keys.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../../Behaviors/QuitGameBehavior.hpp"

using namespace Engine;

class ExitButton : public GameObject {
public:
    ExitButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

        Transform textTransform{
            Point{transform.position.x + 60, transform.position.y + 20},
            LAYER::UI, 0, 1, 1};

        buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
                Text{"Exit", "Fonts/Kenney_Thick.ttf", 16, {0, 0, 0, 255}, textTransform, true},
                Sprite{"Sprites/ui/buttons/button_small_red.png", active},
                Rectangle{{transform.position.x, transform.position.y}, 200, 80},
                std::make_shared<QuitGameBehavior>(true),
                true}));
    };
};


#endif //GOAT_ENGINE_EXITBUTTON_HPP
