//
// Created by Morrowind3 on 18/12/2021.
//

#include "Object_KeyHelpDescription.hpp"
#include "../../../Keys.hpp"

Object_KeyHelpDescription::Object_KeyHelpDescription(std::string description, Transform transform, bool active) : GameObject(transform, active){
    text.insert(std::make_pair(Keys::HELP_KEY_DESCRIPTION, Text{
            std::move(description),
            "Fonts/Kenney_thick.ttf",
            23,
            {0,0,0,255},
            Transform{{transform.position.x,transform.position.y},transform.layerGroup,1, 0,1,1},
            true}));
}
