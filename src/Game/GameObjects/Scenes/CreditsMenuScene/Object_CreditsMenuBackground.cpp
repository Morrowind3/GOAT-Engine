#include "Object_CreditsMenuBackground.hpp"

Object_CreditsMenuBackground::Object_CreditsMenuBackground(Transform transform, bool active) : GameObject(transform,
                                                                                                          active) {
    sprites.insert(
            std::make_pair("Object_CreditsMenuBackground", Sprite{"Sprites/backgrounds/background_mainmenu.png", true}));
    audioSources.insert(std::make_pair("Music", AudioSource{"Music/Wood_Whistles.mp3", AudioSourceType::MUSIC, 20,true, true}));

    std::string font{"Fonts/Kenney_Thick.ttf"};
    Color color{0, 0, 0, 255};

    text.insert(std::make_pair("Title", Text{
            "Credits",
            font,60, color,
            Transform{{750, 150}, transform.layerGroup, 1, 0, 1, 1},
            true}));

    Transform contentTransform{{400, 300}, transform.layerGroup, 1, 0, 1, 1};
    uint8_t contentSize{40};

    text.insert(std::make_pair("Content_1", Text{
        "Made by", font, contentSize, color, contentTransform, true}));

    contentTransform.position.y += 60;
    contentTransform.position.x += 60;
    text.insert(std::make_pair("Content_2", Text{
            "Harley Rombout", font, contentSize, color, contentTransform, true}));

    contentTransform.position.y += 60;
    text.insert(std::make_pair("Content_3", Text{
            "Julian Maas", font, contentSize, color, contentTransform, true}));

    contentTransform.position.y += 60;
    text.insert(std::make_pair("Content_4", Text{
            "Mike Stutje", font, contentSize, color, contentTransform, true}));

    contentTransform.position.y += 60;
    text.insert(std::make_pair("Content_5", Text{
            "Stijn van Loon", font, contentSize, color, contentTransform, true}));

    contentTransform.position.y += 100;
    contentTransform.position.x -= 60;
    text.insert(std::make_pair("Content_6", Text{
            "Special thanks to Bart Luijten", font, contentSize, color, contentTransform, true}));

};
