#ifndef GOAT_ENGINE_BEHAVIOR_DEBUGBUTTON_HPP
#define GOAT_ENGINE_BEHAVIOR_DEBUGBUTTON_HPP

#include "../../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Behavior_DebugButton : public Behavior {
    public: explicit Behavior_DebugButton(AudioSource& enableSound, AudioSource& disableSound, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_DEBUGBUTTON_HPP
