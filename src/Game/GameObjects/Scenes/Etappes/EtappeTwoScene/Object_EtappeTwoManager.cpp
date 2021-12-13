#include "Object_EtappeTwoManager.hpp"
#include "../Behavior_Etappe.hpp"
#include "../../../../Keys.hpp"

Object_EtappeTwoManager::Object_EtappeTwoManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Run_For_Your_Life.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<Behavior_Etappe>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
