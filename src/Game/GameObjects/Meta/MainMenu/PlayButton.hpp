//
// Created by Stijn van Loon on 24-11-2021.
//

#ifndef GOAT_ENGINE_PLAYBUTTON_HPP
#define GOAT_ENGINE_PLAYBUTTON_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Keys.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../../Behaviors/SwitchSceneButtonBehavior.hpp"

using namespace Engine;

class PlayButton : public GameObject {
public:
    PlayButton(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {

        Transform textTransform{
                Point{transform.position.x + (10 * transform.scaleWidth), transform.position.y + (12 * transform.scaleHeight)},
                transform.layer + 1, 0, 1, 1};

        buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
                Text{"Play", "Fonts/Kenney_Thick.ttf", 36, {255, 255, 255, 255}, textTransform, true},
                Sprite{"Sprites/ui/buttons/button_large_blue.png", active},
                Rectangle{Point{transform.position.x, transform.position.y}, 250, 160},
                std::make_shared<SwitchSceneButtonBehavior>("Etappe two", sceneManager, active),
                true}));
    };
};

#endif //GOAT_ENGINE_PLAYBUTTON_HPP
