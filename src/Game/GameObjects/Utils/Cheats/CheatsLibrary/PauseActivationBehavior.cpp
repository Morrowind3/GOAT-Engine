#include "PauseActivationBehavior.hpp"
#include "Scripts/PauseActivationScript.hpp"
#include "../../Keys.hpp"

PauseActivationBehavior::PauseActivationBehavior(GameObject& toggleObject, bool activeOnPause, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseActivationScript>(toggleObject,activeOnPause,true)));
}

PauseActivationBehavior::PauseActivationBehavior(GameComponent& toggleComponent, bool activeOnPause, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseActivationScript>(toggleComponent,activeOnPause,true)));
}
