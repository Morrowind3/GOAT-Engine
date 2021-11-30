#ifndef GOAT_ENGINE_PAUSEACTIVATIONBEHAVIOR_HPP
#define GOAT_ENGINE_PAUSEACTIVATIONBEHAVIOR_HPP

#include "../../GameObjects/Meta/Etappes/BackToEtappeSelectionButton.hpp"

class PauseActivationBehavior : public Behavior {
    public: PauseActivationBehavior(GameObject& toggleObject, bool activeOnPause, bool active);
    public: PauseActivationBehavior(GameComponent& toggleComponent, bool activeOnPause, bool active);
};


#endif //GOAT_ENGINE_PAUSEACTIVATIONBEHAVIOR_HPP
