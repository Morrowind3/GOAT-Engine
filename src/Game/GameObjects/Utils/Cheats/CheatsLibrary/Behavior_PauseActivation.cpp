#include "Behavior_PauseActivation.hpp"
#include "Script_PauseActivation.hpp"
#include "../../../../Keys.hpp"

Behavior_PauseActivation::Behavior_PauseActivation(GameObject& toggleObject, bool activeOnPause, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<Script_PauseActivation>(toggleObject,activeOnPause,true)));
}

Behavior_PauseActivation::Behavior_PauseActivation(GameComponent& toggleComponent, bool activeOnPause, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<Script_PauseActivation>(toggleComponent,activeOnPause,true)));
}
