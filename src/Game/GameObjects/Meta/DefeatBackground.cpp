//
// Created by Morrowind3 on 27/11/2021.
//

#include "DefeatBackground.hpp"

DefeatBackground::DefeatBackground(Transform transform, bool active) : GameObject(transform, active) {
//    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_victory.png", true}));
    text.insert(std::make_pair("Title", Text{
            "git gud",
            "Fonts/Kenney_Thick.ttf",
            60,
            {0,0,0,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{425,150},transform.layer,0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Little Blue Box Car.mp3", AudioSourceType::MUSIC, true, true}));
}
