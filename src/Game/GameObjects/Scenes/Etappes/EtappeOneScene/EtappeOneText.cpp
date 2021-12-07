#include "EtappeOneText.hpp"

EtappeOneText::EtappeOneText(Transform transform, bool active) : GameObject(transform, active) {
    const auto& X = transform.position.x;
    const auto& Y = transform.position.y;
    text.insert(std::make_pair("Welcome", Text{
            "Welcome to the tutorial, press ESC if you need a break",
            "Fonts/Kenney_Thick.ttf",
            20,
            {0,0,0,255},
            Transform{{800 + X, 200 + Y}, transform.layerGroup, 1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_1", Text{
            "Use D to move forwards and A to move backwards",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{800 + X, 600 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_2", Text{
            "Press space to jump",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{2200 + X, 400 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_3", Text{
            "Evade angry enemies",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{3800 + X, 0 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_4", Text{
            "Press space twice to double jump",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{5200 + X, -200 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_5", Text{
            "If you are damaged you can heal with a Jagerpleister",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{4400 + X, 150 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_6", Text{
            "Pick up waste with S to save the environment",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{6700 + X, 0 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_7", Text{
            "Welcome to the finish flag",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{7700 + X, 0 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
    text.insert(std::make_pair("Tutorial_8", Text{
            "press the backtick button if you like cheats",
            "Fonts/Kenney_Thick.ttf",
            16,
            {0,0,0,255},
            Transform{{7600 + X, 40 + Y}, transform.layerGroup,1, 0, 1, 1},
            true}));
}