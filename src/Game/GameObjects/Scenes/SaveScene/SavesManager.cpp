#include "SavesManager.hpp"
#include "../../../Keys.hpp"
#include "SavesManagerBehavior.hpp"
#include "../../../AudioSources/Music/Music_SmoothGroove.hpp"
#include "../../../Layers.hpp"

SavesManager::SavesManager(Scene& scene, bool active): GameObject(Transform{{0,0}}, active) {
    behaviors.insert(std::make_pair(Keys::_, std::make_shared<SavesManagerBehavior>(scene,true)));
    // Background stuff
    text.insert(std::make_pair(Keys::_, Text {
            "Mount Everestimate","Fonts/Kenney_Thick.ttf",
            48, {0,0,0,255},
            Transform{{180,35},LAYER::UI,1,0,1,1},
            true}));
    audioSources.insert(std::make_pair(Keys::_, Music_SmoothGroove(0, 100, true, true)));
}
