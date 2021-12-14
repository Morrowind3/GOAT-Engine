#include "Object_ScoreboardAllEtappesButton.hpp"
#include "../../../../Keys.hpp"
#include "../Behavior_LoadScoreboard.hpp"

Object_ScoreboardAllEtappesButton::Object_ScoreboardAllEtappesButton(Text& scoreboardHeader, Transform transform, bool active):
GameObject(transform,active) {
    Transform textTransform{
            Point{transform.position.x+8, transform.position.y+25},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};

    buttons.insert(std::make_pair(Keys::_, Button {
            Text{"Total", "Fonts/Kenney_Thick.ttf", 16, {255,255,255,255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/Button_large_blue.png", true},
            Rectangle{{transform.position.x, transform.position.y}, 100, 64},
            std::make_shared<Behavior_LoadScoreboard>(scoreboardHeader, true),
            true
    }));
}
