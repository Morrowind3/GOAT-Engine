#include "Object_EtappeOneManager.hpp"
#include "../../../../Keys.hpp"
#include "../Behavior_Etappe.hpp"

Object_EtappeOneManager::Object_EtappeOneManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::MUSIC,AudioSource{"Music/Busy_Schedule.mp3", AudioSourceType::MUSIC, true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_normal.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<Behavior_Etappe>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
