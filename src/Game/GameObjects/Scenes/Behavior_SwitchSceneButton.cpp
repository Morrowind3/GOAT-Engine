#include "Behavior_SwitchSceneButton.hpp"
#include "Script_SwitchSceneButton.hpp"
#include "../../Keys.hpp"

Behavior_SwitchSceneButton::Behavior_SwitchSceneButton(const std::string& levelName, AudioSource& nopeSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Script_SwitchSceneButton>(levelName, &nopeSound, true)));
}

Behavior_SwitchSceneButton::Behavior_SwitchSceneButton(const std::string& levelName, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Script_SwitchSceneButton>(levelName, true)));
}


