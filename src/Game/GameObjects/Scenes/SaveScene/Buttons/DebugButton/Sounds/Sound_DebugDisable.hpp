#ifndef GOAT_ENGINE_SOUND_DEBUGDISABLE_HPP
#define GOAT_ENGINE_SOUND_DEBUGDISABLE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_DebugDisable: public AudioSource {
    public: Sound_DebugDisable(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_DEBUGDISABLE_HPP
