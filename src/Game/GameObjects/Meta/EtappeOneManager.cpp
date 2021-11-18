#include "EtappeOneManager.hpp"

EtappeOneManager::EtappeOneManager(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(ETAPPE_ONE::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    audioSources.insert(std::make_pair(ETAPPE_ONE::SNOWSTORM,AudioSource{"Music/Snowstorm.wav", AudioSourceType::MUSIC, true, true}));
}
