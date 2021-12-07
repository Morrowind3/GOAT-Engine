#include "EtappeFourManager.hpp"
#include "../../../../Keys.hpp"
#include "../EtappeBehavior.hpp"

EtappeFourManager::EtappeFourManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Midnight_Snow.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_white.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
