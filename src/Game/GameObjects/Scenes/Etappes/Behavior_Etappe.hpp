#ifndef GOAT_ENGINE_BEHAVIOR_ETAPPE_HPP
#define GOAT_ENGINE_BEHAVIOR_ETAPPE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Behavior_Etappe : public Behavior {
    public: Behavior_Etappe(int startHpAmount, AudioSource& pauseSound, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_ETAPPE_HPP
