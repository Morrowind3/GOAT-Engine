#include "Object_EtappeThreeManager.hpp"
#include "../../../../Keys.hpp"
#include "../Behavior_Etappe.hpp"

Object_EtappeThreeManager::Object_EtappeThreeManager(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Boogi_Marabi.mp3", AudioSourceType::MUSIC, 20,true, true}));
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_gray.png", true}));
    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::ETAPPE, std::make_shared<Behavior_Etappe>(3, audioSources.at(Keys::PAUSE_SFX), true)));
}
