#include "VictoryScreenManager.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../VictoryScene/VictorySceneBehavior.hpp"

VictoryScreenManager::VictoryScreenManager(Transform transform, bool active) : GameObject(transform, active) {
    std::string time = Globals::getInstance().sceneExists(Keys::TEXT) ? Globals::getInstance().sceneGet(Keys::TEXT) : "";

    sprites.insert(std::make_pair("Background", Sprite{"Sprites/backgrounds/background_victory.png", true}));
    text.insert(std::make_pair("Title", Text{
            "A winner is you",
            "Fonts/Kenney_Thick.ttf",
            60,
            {255,255,255,255},
            Transform{{530,40},transform.layerGroup,1, 0,1,1},
            true}));
    text.insert(std::make_pair("Garbage", Text{
            "Garbage collected",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{210,580},transform.layerGroup,1, 0,1,1},
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
    text.insert(std::make_pair("Score", Text{
            "Score",
            "Fonts/Kenney_Thick.ttf",
            40,
            {255,255,255,255},
            Transform{{670,740},transform.layerGroup,1, 0,1,1},
            true}));
    audioSources.insert(std::make_pair("Music",AudioSource{"Sounds/victory.mp3", AudioSourceType::SAMPLE, true, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictorySceneBehavior>(true)));
}
