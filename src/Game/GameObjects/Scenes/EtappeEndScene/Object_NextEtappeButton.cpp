#include "Object_NextEtappeButton.hpp"
#include "../../../Keys.hpp"
#include "../Behavior_SwitchSceneButton.hpp"
#include "../../../Layers.hpp"

Object_NextEtappeButton::Object_NextEtappeButton(Transform transform, bool active) : GameObject(transform, active) {
    Transform textTransform{
            Point{transform.position.x + 95, transform.position.y + 40},
            LAYER::UI, 1,0, 1, 1};

    audioSources.insert(std::make_pair(Keys::FALSE, AudioSource{"Sounds/Nope.ogg",AudioSourceType::SAMPLE,true}));
    buttons.insert(std::make_pair(Keys::NEXT_ETAPPE, Button{
            Text{"Next", "Fonts/Kenney_Thick.ttf", 35, {255, 255, 255, 255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/button_outline_white.png", active},
            Rectangle{{transform.position.x, transform.position.y}, 200, 80},
            std::make_shared<Behavior_SwitchSceneButton>(Keys::NEXT_ETAPPE, audioSources.at(Keys::FALSE), true),
            true}));
}
