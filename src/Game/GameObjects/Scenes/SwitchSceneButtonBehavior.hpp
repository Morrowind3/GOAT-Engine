#ifndef GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
#define GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP

#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class SwitchSceneButtonBehavior : public Behavior {
    public:
        SwitchSceneButtonBehavior(const std::string& levelName, AudioSource& nopeSound, bool active);
        SwitchSceneButtonBehavior(const std::string& levelName, bool active);
};


#endif //GOAT_ENGINE_SWITCHSCENEBUTTONBEHAVIOR_HPP
