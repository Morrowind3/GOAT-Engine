#include "EtappeTwoManager.hpp"
#include "../../../Behaviors/Utils/EtappeBehavior.hpp"
#include "../../../Keys.hpp"

EtappeTwoManager::EtappeTwoManager(Transform transform, bool active) : GameObject(transform, active) {
//    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Run For Your Life.mp3", AudioSourceType::MUSIC, true, true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX,AudioSource{"Sounds/Pause.ogg", AudioSourceType::SAMPLE, false, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<EtappeBehavior>(2, true)));
}
