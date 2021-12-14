#ifndef GOAT_ENGINE_SOUND_DEBUGENABLE_HPP
#define GOAT_ENGINE_SOUND_DEBUGENABLE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_DebugEnable: public AudioSource {
    public: Sound_DebugEnable(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_DEBUGENABLE_HPP
