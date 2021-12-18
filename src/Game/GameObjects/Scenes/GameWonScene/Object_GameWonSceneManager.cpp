#include "Object_GameWonSceneManager.hpp"
#include "../../../Keys.hpp"
#include "../VictoryScene/Behavior_VictoryScreen.hpp"

Object_GameWonSceneManager::Object_GameWonSceneManager(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::GAME_WON_SCREEN, Sprite{"Sprites/backgrounds/background_game_won.png", true}));
    text.insert(std::make_pair("Title", Text{
            "You reached the summit",
            "Fonts/Kenney_Thick.ttf",
            60,
            {6,45,15,255},
            Transform{{525,40},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("GarbageLabel", Text{
            "Garbage collected",
            "Fonts/Kenney_Thick.ttf",
            60,
            {12,90,30,255},
            Transform{{70,400},transform.layerGroup,1, 0,1,1},
            true}));
    Text& trashText = text.insert(std::make_pair("GarbageCount", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            60,
            {12,90,30,255},
            Transform{{1100,330},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    text.insert(std::make_pair("Timelabel", Text{
            "Time",
            "Fonts/Kenney_Thick.ttf",
            60,
            {18,135,45,255},
            Transform{{825,520},transform.layerGroup,1, 0,1,1},
            true}));
    Text& timeText = text.insert(std::make_pair("Timestamp", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            60,
            {18,135,45,255},
            Transform{{1100,450},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    text.insert(std::make_pair("ScoreLabel", Text{
            "Score",
            "Fonts/Kenney_Thick.ttf",
            60,
            {24,180,60,255},
            Transform{{770,640},transform.layerGroup,1, 0,1,1},
            true}));
    Text& scoreText = text.insert(std::make_pair("Score", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            60,
            {24,180,60,255},
            Transform{{1100,570},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    audioSources.insert(std::make_pair(Keys::_,AudioSource{"Music/Unidentified_Flying_Scotsman.mp3", AudioSourceType::MUSIC, 80,true, true}));
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<Behavior_VictoryScreen>(trashText,timeText,scoreText,true)));
}
