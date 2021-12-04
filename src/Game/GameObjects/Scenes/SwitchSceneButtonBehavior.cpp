#include "SwitchSceneButtonBehavior.hpp"
#include "SwitchSceneButtonScript.hpp"
#include "../../Keys.hpp"

SwitchSceneButtonBehavior::SwitchSceneButtonBehavior(const std::string& levelName, SceneManager& sceneManager, AudioSource& nopeSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<SwitchSceneButtonScript>(levelName, sceneManager, &nopeSound, true)));
}

SwitchSceneButtonBehavior::SwitchSceneButtonBehavior(const std::string& levelName, SceneManager& sceneManager, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<SwitchSceneButtonScript>(levelName, sceneManager, true)));
}


