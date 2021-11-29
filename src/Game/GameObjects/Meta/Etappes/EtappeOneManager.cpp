#include "EtappeOneManager.hpp"
#include "../../../Keys.hpp"
#include "../../../Behaviors/Utils/EtappeBehavior.hpp"

EtappeOneManager::EtappeOneManager(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, true)));
    audioSources.insert(std::make_pair(Keys::SNOWSTORM,AudioSource{"Music/Busy_Schedule.mp3", AudioSourceType::MUSIC, true, true}));
}
