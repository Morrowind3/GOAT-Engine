#include "DefeatBackground.hpp"

DefeatBackground::DefeatBackground(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_defeat.png", true}));
    text.insert(std::make_pair("Title", Text{
            "You everestimated yourself",
            "Fonts/Kenney_Thick.ttf",
            60,
            {100,0,0,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{250,70},transform.layer,0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Little_Blue_Box_Car.mp3", AudioSourceType::MUSIC, true, true}));
}