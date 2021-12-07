#include "EtappeThreeManager.hpp"
#include "../../../../Keys.hpp"
#include "../EtappeBehavior.hpp"

EtappeThreeManager::EtappeThreeManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Boogi_Marabi.mp3", AudioSourceType::MUSIC, 20,true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_gray.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
