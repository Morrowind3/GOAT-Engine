//
// Created by Morrowind3 on 18/12/2021.
//

#include "Object_GameWonSceneManager.hpp"
#include "../../../Keys.hpp"

Object_GameWonSceneManager::Object_GameWonSceneManager(Transform transform, bool active) : GameObject(transform,
                                                                                                      active) {
    sprites.insert(std::make_pair(Keys::GAME_WON_SCREEN, Sprite{"Sprites/backgrounds/background_game_won.png", true}));
    text.insert(std::make_pair("Title", Text{
            "You reached the top",
            "Fonts/Kenney_Thick.ttf",
            60,
            {0,255,0,255},
            Transform{{675,40},transform.layerGroup,1, 0,1,1},
            true}));
    audioSources.insert(std::make_pair(Keys::_,AudioSource{"Music/Unidentified Flying Scotsman.mp3", AudioSourceType::MUSIC, 35,true, true}));

}
