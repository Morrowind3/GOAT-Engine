#include "Object_DebugButton.hpp"
#include "../../../../../Keys.hpp"
#include "../../../../../Layers.hpp"
#include "Behavior_DebugButton.hpp"
#include "Sounds/Sound_DebugEnable.hpp"
#include "Sounds/Sound_DebugDisable.hpp"

Object_DebugButton::Object_DebugButton(Transform transform, bool active) : GameObject(transform, active) {

    Transform textTransform{
            Point{transform.position.x + 50, transform.position.y + 20},
            LAYER::UI, 1, 0, 1, 1};

    auto& enableSound = audioSources.insert(std::make_pair(Keys::TRUE, Sound_DebugEnable{1,100,false,true})).first->second;
    auto& disableSound = audioSources.insert(std::make_pair(Keys::FALSE, Sound_DebugDisable{1,100,false,true})).first->second;

    buttons.insert(std::make_pair(Keys::QUIT_GAME, Button{
            Text{"Toggle logging", "Fonts/Kenney_Thick.ttf", 16, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_smallwide_red.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 325, 65},
            std::make_shared<Behavior_DebugButton>(enableSound,disableSound,true),
            true}));
}