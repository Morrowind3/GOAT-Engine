#include "EtappeOneManager.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/EtappeBehavior.hpp"

EtappeOneManager::EtappeOneManager(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Snowstorm.mp3", AudioSourceType::MUSIC, true, true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX,AudioSource{"Sounds/Pause.ogg", AudioSourceType::SAMPLE, false, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(audioSources.at(Keys::PAUSE_SFX), true)));
}
