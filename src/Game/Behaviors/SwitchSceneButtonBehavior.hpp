#ifndef GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
#define GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP

#include "Scripts/SwitchSceneButtonScript.hpp"

using namespace Engine;

class SwitchSceneButtonBehavior : public Behavior {
    public:
        SwitchSceneButtonBehavior(const std::string& levelName, SceneManager& sceneManager, bool active) : Behavior(active) {
            scripts.emplace_back(std::make_shared<SwitchSceneButtonScript>(levelName, sceneManager, true));
        }
};


#endif //GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
