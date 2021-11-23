#ifndef GOAT_ENGINE_BACKGROUND_HPP
#define GOAT_ENGINE_BACKGROUND_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class Background : public GameObject {
public:
    Background(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {
        sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_mainmenu.png", true}));
    };
};

#endif //GOAT_ENGINE_BACKGROUND_HPP
