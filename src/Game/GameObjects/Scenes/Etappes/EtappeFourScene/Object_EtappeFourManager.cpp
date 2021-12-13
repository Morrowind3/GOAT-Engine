#include "Object_EtappeFourManager.hpp"
#include "../../../../Keys.hpp"
#include "../Behavior_Etappe.hpp"

Object_EtappeFourManager::Object_EtappeFourManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Midnight_Snow.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_white.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<Behavior_Etappe>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
