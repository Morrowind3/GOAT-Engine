#include "EtappeTwoManager.hpp"

EtappeTwoManager::EtappeTwoManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Run For Your Life.mp3", AudioSourceType::MUSIC, true, true}));
}
