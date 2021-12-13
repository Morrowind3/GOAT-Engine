#include "Object_EtappeSelectionBackground.hpp"
#include "../../../Keys.hpp"

Object_EtappeSelectionBackground::Object_EtappeSelectionBackground(Transform transform, bool active) : GameObject(transform, active) {
    // Start-up SFX
    audioSources.insert(std::make_pair(Keys::AUDIO, AudioSource{"Sounds/EtappeSelect.ogg",AudioSourceType::SAMPLE,true,true}));
    // Object_MainMenuBackground
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/mountains.png", true}));
    // Music
    audioSources.insert(std::make_pair(Keys::MUSIC,AudioSource{"Music/Coconut_Run.mp3", AudioSourceType::MUSIC, true, true}));
}
