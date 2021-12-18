//
// Created by Morrowind3 on 18/12/2021.
//

#include "Object_KeyHelpEntry.hpp"

#include <utility>
#include "../../../Keys.hpp"

Object_KeyHelpEntry::Object_KeyHelpEntry(std::string description, Transform transform, bool active) : GameObject(transform, active){

    text.insert(std::make_pair(Keys::HELP_KEY_DESCRIPTION, Text{
            std::move(description),
            "Fonts/Kenney_thick.ttf",
            40,
            {0,0,0,255},
            Transform{{transform.position.x+300,transform.position.y+25},transform.layerGroup,1, 0,1,1},
            true}));
}
