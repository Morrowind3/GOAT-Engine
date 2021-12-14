#include "Object_ScoreboardSpecificEtappeButton.hpp"
#include "../../../../Keys.hpp"
#include "Behavior_LoadScoreboardButton.hpp"
#include "Sound_Navigate.hpp"

Object_ScoreboardSpecificEtappeButton::Object_ScoreboardSpecificEtappeButton(unsigned short etappeNumber, Text& scoreboardHeader, Transform transform, bool active):
GameObject(transform,active) {

    Transform textTransform{
            Point{transform.position.x+10, transform.position.y+10},
            transform.layerGroup, transform.layerInsideGroup+1, 0, 1, 1};
    auto& clickSound = audioSources.insert(std::make_pair(Keys::_, Sound_Navigate{1,70,false,true})).first->second;
    buttons.insert(std::make_pair(Keys::_, Button {
            Text{std::to_string(etappeNumber), "Fonts/Kenney_Thick.ttf", 32, {255,255,255,255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/Button_square_blue.png", true},
            Rectangle{{transform.position.x, transform.position.y}, 67, 64},
            std::make_shared<Behavior_LoadScoreboardButton>(etappeNumber, scoreboardHeader, clickSound, true),
            true
    }));

}
