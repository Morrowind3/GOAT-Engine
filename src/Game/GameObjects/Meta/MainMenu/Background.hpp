#ifndef GOAT_ENGINE_BACKGROUND_HPP
#define GOAT_ENGINE_BACKGROUND_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Background : public GameObject {
public:
    Background(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {
        sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_mainmenu.png", true}));
        text.insert(std::make_pair("Title", Text{
            "Mount Everestimate",
            "Fonts/Kenney_Thick.ttf",
            80,
            {0,0,0,255},
            Transform{{250,150},LAYER::PARALLAX_BACKGROUND,0,1,1},
            true}));
//        audioSources.insert(std::make_pair("Music",AudioSource{"Music/Snowstorm.wav", AudioSourceType::MUSIC, true, true}));
        audioSources.insert(std::make_pair("Music",AudioSource{"Music/Journey.mp3", AudioSourceType::MUSIC, true, true}));
    };
};

#endif //GOAT_ENGINE_BACKGROUND_HPP
