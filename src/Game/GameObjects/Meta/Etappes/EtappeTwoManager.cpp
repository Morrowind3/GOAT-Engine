#include "EtappeTwoManager.hpp"
#include "../../../Behaviors/Utils/EtappeBehavior.hpp"
#include "../../../Keys.hpp"

EtappeTwoManager::EtappeTwoManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Run_For_Your_Life.mp3", AudioSourceType::MUSIC, true, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(3, true)));
}
