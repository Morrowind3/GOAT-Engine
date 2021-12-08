#include "VictoryScreenManager.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../VictoryScene/VictorySceneBehavior.hpp"

VictoryScreenManager::VictoryScreenManager(Transform transform, bool active) : GameObject(transform, active) {
    Globals& globals = Globals::getInstance();
    // TODO: This can't exist in scene scope AFAIK
    std::string time = globals.sceneExists(Keys::TEXT) ? globals.sceneGet(Keys::TEXT) : "0";
    std::string trash = globals.sceneExists(Keys::TRASH) ? globals.sceneGet(Keys::TRASH) : "0";
    int seconds = globals.sceneExists(Keys::TIMER) ? std::stoi(globals.sceneGet(Keys::TIMER))/1000 : 0;

    int score = 1000 + (std::stoi(trash) * 150) - (seconds / 20 * 200) -  ((3 - std::stoi(globals.sceneGet(Keys::HP))) * 300);

    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_victory.png", true}));
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
    text.insert(std::make_pair("GarbageCount", Text{
            trash,
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,540},transform.layerGroup,0, 0,1,1},
            true}));
    text.insert(std::make_pair("Timelabel", Text{
            "Time",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{705,660},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("Timestamp", Text{
            time,
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,620},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("ScoreLabel", Text{
            "Score",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{670,740},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("Score", Text{
            std::to_string(score),
            "Fonts/pixeled.ttf",
            40,
            {255,255,255,255},
            Transform{{920,700},transform.layerGroup,0, 0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Sounds/victory.mp3", AudioSourceType::SAMPLE, true, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictorySceneBehavior>(true)));
}
