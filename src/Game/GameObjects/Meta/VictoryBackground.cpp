//
// Created by Morrowind3 on 27/11/2021.
//

#include "VictoryBackground.hpp"

VictoryBackground::VictoryBackground(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_victory.png", true}));
    text.insert(std::make_pair("Title", Text{
            "A winner is you!",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{550,10},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Rank", Text{
            "Rank ",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{700,90},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Garbage", Text{
            "Garbage collected",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{500,600},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Time", Text{
            "Time",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            //Transform{{250,150},LAYER::UI,0,1,1},
            Transform{{500,700},transform.layer,0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Sounds/victory.mp3", AudioSourceType::SAMPLE, true, true}));

}
