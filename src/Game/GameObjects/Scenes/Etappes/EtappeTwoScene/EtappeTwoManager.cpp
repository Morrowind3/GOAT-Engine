#include "EtappeTwoManager.hpp"
#include "../EtappeBehavior.hpp"
#include "../../../../Keys.hpp"

EtappeTwoManager::EtappeTwoManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Run_For_Your_Life.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
