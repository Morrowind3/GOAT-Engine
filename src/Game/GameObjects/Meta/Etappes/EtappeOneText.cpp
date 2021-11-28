#include "EtappeOneText.hpp"

EtappeOneText::EtappeOneText(Transform transform, bool active) : GameObject(transform, active) {
    text.insert(std::make_pair("Welcome", Text{
            "Welcome to the tutorial",
            "Fonts/Kenney_Thick.ttf",
            20,
            {0,0,0,255},
            Transform{{800,200},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Tutorial_1", Text{
            "Use D to move forwards and A to move backwards",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{800,600},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Tutorial_2", Text{
            "Press space to jump",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{2200,400},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Tutorial_3", Text{
            "Evade angry enemies",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{3800,400},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Tutorial_4", Text{
            "Press space twice to double jump",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{5200,200},transform.layer,0,1,1},
            true}));

    text.insert(std::make_pair("Tutorial_5", Text{
            "Finish",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{7200,0},transform.layer,0,1,1},
            true}));
}