#include "Object_VictoryScreenManager.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "Behavior_VictoryScreen.hpp"

Object_VictoryScreenManager::Object_VictoryScreenManager(Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair("Object_MainMenuBackground", Sprite{"Sprites/backgrounds/background_victory.png", true}));
    text.insert(std::make_pair("Title", Text{
            "A winner is you",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            Transform{{530,40},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("GarbageLabel", Text{
            "Garbage collected",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{210,580},transform.layerGroup,1, 0,1,1},
            true}));
    Text& trashText = text.insert(std::make_pair("GarbageCount", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,540},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    text.insert(std::make_pair("Timelabel", Text{
            "Time",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{705,660},transform.layerGroup,1, 0,1,1},
            true}));
    Text& timeText = text.insert(std::make_pair("Timestamp", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,620},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    text.insert(std::make_pair("ScoreLabel", Text{
            "Score",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{670,740},transform.layerGroup,1, 0,1,1},
            true}));
    Text& scoreText = text.insert(std::make_pair("Score", Text{
            std::string{},
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,700},transform.layerGroup,1, 0,1,1},
            true})).first->second;
    audioSources.insert(std::make_pair(Keys::_,AudioSource{"Sounds/Victory.ogg", AudioSourceType::SAMPLE, 35,true, true}));
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<Behavior_VictoryScreen>(trashText,timeText,scoreText,true)));
}
