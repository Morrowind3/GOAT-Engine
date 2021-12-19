#include "Object_KeyHelpKey.hpp"
#include "../../../Keys.hpp"

using namespace Engine;

Object_KeyHelpKey::Object_KeyHelpKey(const std::string& key,  Transform transform, bool active) : GameObject(transform, active){
    uint8_t fontSize = key.size() > 1 ? 14 : 40;

    sprites.insert(std::make_pair(Keys::HELP_KEY_SPRITE + key, Sprite{"Sprites/ui/buttons/Button_square_white.png",true}));
    text.insert(std::make_pair(Keys::HELP_KEY_SPRITE + key, Text{
                key,
                "Fonts/Kenney_thick.ttf",
                fontSize,
                {100,100,100,255},
                Transform{{transform.position.x+15,transform.position.y+20},transform.layerGroup,1, 0,1,1},
                true}));
}

