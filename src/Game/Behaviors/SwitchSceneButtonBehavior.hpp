#ifndef GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
#define GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP

#include "../../Engine/SceneManager.hpp"

using namespace Engine;

class SwitchSceneButtonBehavior : public Behavior {
    public: SwitchSceneButtonBehavior(const std::string& levelName, SceneManager& sceneManager, bool active);
};


#endif //GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
