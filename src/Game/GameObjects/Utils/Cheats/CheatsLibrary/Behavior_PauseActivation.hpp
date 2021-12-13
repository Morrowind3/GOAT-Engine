#ifndef GOAT_ENGINE_BEHAVIOR_PAUSEACTIVATION_HPP
#define GOAT_ENGINE_BEHAVIOR_PAUSEACTIVATION_HPP

#include "../../../Scenes/Etappes/Object_BackToEtappeSelectionButton.hpp"

class Behavior_PauseActivation : public Behavior {
    public: Behavior_PauseActivation(GameObject& toggleObject, bool activeOnPause, bool active);
    public: Behavior_PauseActivation(GameComponent& toggleComponent, bool activeOnPause, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_PAUSEACTIVATION_HPP
