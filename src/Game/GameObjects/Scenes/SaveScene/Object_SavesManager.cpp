#include "Object_SavesManager.hpp"
#include "../../../Keys.hpp"
#include "Behavior_SavesManager.hpp"
#include "../../../Music/Music_SmoothGroove.hpp"
#include "../../../Layers.hpp"
#include "Decor/Sprite_SaveBackground.hpp"

Object_SavesManager::Object_SavesManager(bool active): GameObject(Transform{{0,0}}, active) {
    // Logic
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<Behavior_SavesManager>(true)));

    // Background stuff
    sprites.insert(std::make_pair(Keys::_, Sprite_SaveBackground{true}));
    text.insert(std::make_pair(Keys::_, Text {
            "Select a save file","Fonts/Kenney_Thick.ttf",
            48, {0,0,0,255},
            Transform{{255,35},LAYER::UI,1,0,1,1},
            true}));
    audioSources.insert(std::make_pair(Keys::_, Music_SmoothGroove(0, 100, true, true)));
}
