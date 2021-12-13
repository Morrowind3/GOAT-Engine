#ifndef GOAT_ENGINE_BEHAVIOR_SWITCHSCENEBUTTON_HPP
#define GOAT_ENGINE_BEHAVIOR_SWITCHSCENEBUTTON_HPP

#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class Behavior_SwitchSceneButton : public Behavior {
    public:
        Behavior_SwitchSceneButton(const std::string& levelName, AudioSource& nopeSound, bool active);
        Behavior_SwitchSceneButton(const std::string& levelName, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_SWITCHSCENEBUTTON_HPP
