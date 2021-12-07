#include "EtappeFiveManager.hpp"
#include "../../../../Keys.hpp"
#include "../EtappeBehavior.hpp"

EtappeFiveManager::EtappeFiveManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Deep_Down_Chemistry.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_red.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
