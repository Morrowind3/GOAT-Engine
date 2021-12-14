#include "Object_ScoreboardManager.hpp"
#include "../../../Keys.hpp"
#include "../../../Music/Music_WoodWhistles.hpp"
#include "../../../Layers.hpp"
#include "Behavior_LoadScoreboard.hpp"
#include "Decor/Sprite_ScoreboardBackground.hpp"

Object_ScoreboardManager::Object_ScoreboardManager(bool active) : GameObject(Transform{{0,0}}, active) {
    // Background stuff
    sprites.insert(std::make_pair(Keys::_, Sprite_ScoreboardBackground{true}));
    auto& scoreboardHeader = text.insert(std::make_pair(Keys::TEXT, Text {
            "Scoreboard","Fonts/Kenney_Thick.ttf",
            48, {255,255,255,255},
            Transform{{110,35},LAYER::UI,1,0,1,1},
            true})).first->second;
    audioSources.insert(std::make_pair(Keys::_, Music_WoodWhistles{0,100,true,true}));

    // Logic
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<Behavior_LoadScoreboard>(scoreboardHeader,true)));
}
