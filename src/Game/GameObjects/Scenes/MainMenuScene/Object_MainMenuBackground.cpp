#include "Object_MainMenuBackground.hpp"

Object_MainMenuBackground::Object_MainMenuBackground(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair("Object_MainMenuBackground", Sprite{"Sprites/backgrounds/background_mainmenu.png", true}));
    text.insert(std::make_pair("Title", Text{
            "Mount Everestimate",
            "Fonts/Kenney_Thick.ttf",
            60,
            {0,0,0,255},
            Transform{{425,150},transform.layerGroup,1,0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Music/Journey.mp3", AudioSourceType::MUSIC, true, true}));
};
