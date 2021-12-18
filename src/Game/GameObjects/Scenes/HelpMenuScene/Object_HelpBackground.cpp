//
// Created by Morrowind3 on 18/12/2021.
//

#include "Object_HelpBackground.hpp"
#include "../../../Keys.hpp"
#include "../SaveScene/Decor/Sprite_SaveBackground.hpp"

Object_HelpBackground::Object_HelpBackground(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::BACKGROUND, Sprite{"Sprites/backgrounds/background_mainmenu.png", true}));
    audioSources.insert(std::make_pair("Music", AudioSource{"Music/Wood_Whistles.mp3", AudioSourceType::MUSIC, 20,true, true}));

}
