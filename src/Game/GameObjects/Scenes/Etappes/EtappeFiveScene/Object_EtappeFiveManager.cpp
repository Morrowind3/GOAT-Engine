#include "Object_EtappeFiveManager.hpp"
#include "../../../../Keys.hpp"
#include "../Behavior_Etappe.hpp"

Object_EtappeFiveManager::Object_EtappeFiveManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Deep_Down_Chemistry.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_red.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<Behavior_Etappe>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
