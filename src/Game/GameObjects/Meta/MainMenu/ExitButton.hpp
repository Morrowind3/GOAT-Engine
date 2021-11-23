#ifndef GOAT_ENGINE_EXITBUTTON_HPP
#define GOAT_ENGINE_EXITBUTTON_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Keys.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../Behaviors/QuitGameBehavior.hpp"

using namespace Engine;

class ExitButton : public GameObject {
public:
    ExitButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(Transform{{0, 0}, 100}, active) {
//        buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
//                Text{"Exit", "Fonts/Kenney_Thick.ttf", 16, {0, 0, 0, 255}, transform, true},
//                Color{255, 0, 0, 255},
//                Rectangle{{0, 540}, 1280, 540},
//                std::make_shared<QuitGameBehavior>(true),
//                true}));
    };
};


#endif //GOAT_ENGINE_EXITBUTTON_HPP
