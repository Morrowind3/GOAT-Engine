#ifndef GOAT_ENGINE_ETAPPEBEHAVIOR_HPP
#define GOAT_ENGINE_ETAPPEBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class EtappeBehavior : public Behavior {
    public: EtappeBehavior(int startHpAmount, bool active);
};

#endif //GOAT_ENGINE_ETAPPEBEHAVIOR_HPP
