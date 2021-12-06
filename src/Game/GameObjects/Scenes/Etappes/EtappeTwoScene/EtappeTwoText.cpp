#include "EtappeTwoText.hpp"

EtappeTwoText::EtappeTwoText(Transform transform, bool active) : GameObject(transform, active) {
    const auto& X = transform.position.x;
    const auto& Y = transform.position.y;
    text.insert(std::make_pair("timer_1", Text{
            "Others are trying to beat you to the top",
            "Fonts/Kenney_Thick.ttf",
            20,
            {0,0,0,255},
            Transform{{800 + X, 500 + Y}, transform.layerGroup, 0, 1, 1},
            true}));
    text.insert(std::make_pair("timer_2", Text{
            "Stay ahead of the line if you want a shot at the high score",
            "Fonts/Kenney_Thick.ttf",
            20,
            {0,0,0,255},
            Transform{{1700 + X, 200+Y}, transform.layerGroup, 0, 1, 1},
            true}));
}
