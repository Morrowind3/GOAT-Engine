#include "EtappeSelectionBackground.hpp"
#include "../../../Keys.hpp"

EtappeSelectionBackground::EtappeSelectionBackground(Transform transform, bool active) : GameObject(transform, active) {
    // Start-up SFX
    audioSources.insert(std::make_pair(Keys::AUDIO, AudioSource{"Sounds/EtappeSelect.ogg",AudioSourceType::SAMPLE,true,true}));
    // Background
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/mountains.png", true}));
}
