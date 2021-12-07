#include "VictoryScreenManager.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../VictoryScene/VictorySceneBehavior.hpp"

VictoryScreenManager::VictoryScreenManager(Transform transform, bool active) : GameObject(transform, active) {
    std::string time = Globals::getInstance().sceneExists(Keys::TEXT) ? Globals::getInstance().sceneGet(Keys::TEXT) : "0";
    std::string trash = Globals::getInstance().sceneExists(Keys::TRASH) ? Globals::getInstance().sceneGet(Keys::TRASH) : "0";
    int seconds = Globals::getInstance().sceneExists(Keys::TIMER) ? std::stoi(Globals::getInstance().sceneGet(Keys::TIMER))/1000 : 0;

    int score = 1000 + (std::stoi(trash) * 150) - (seconds / 20 * 200) -  ((3 - std::stoi(Globals::getInstance().sceneGet(Keys::HP))) * 300);


    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_victory.png", true}));
    text.insert(std::make_pair("Title", Text{
            "A winner is you",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            Transform{{530,40},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("GarbageLabel", Text{
            "Garbage collected",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{210,580},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("GarbageCount", Text{
            trash,
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,540},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Timelabel", Text{
            "Time",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{705,660},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Timestamp", Text{
            time,
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,620},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("ScoreLabel", Text{
            "Score",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{670,740},transform.layer,0,1,1},
            true}));
    text.insert(std::make_pair("Score", Text{
            std::to_string(score),
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,700},transform.layer,0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Sounds/victory.mp3", AudioSourceType::SAMPLE, true, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictorySceneBehavior>(true)));
}
