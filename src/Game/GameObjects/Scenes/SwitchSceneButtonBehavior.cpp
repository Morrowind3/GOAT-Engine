#include "SwitchSceneButtonBehavior.hpp"
#include "SwitchSceneButtonScript.hpp"
#include "../../Keys.hpp"

SwitchSceneButtonBehavior::SwitchSceneButtonBehavior(const std::string& levelName, AudioSource& nopeSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<SwitchSceneButtonScript>(levelName, &nopeSound, true)));
}

SwitchSceneButtonBehavior::SwitchSceneButtonBehavior(const std::string& levelName, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<SwitchSceneButtonScript>(levelName, true)));
}


