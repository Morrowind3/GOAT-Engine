#ifndef GOAT_ENGINE_SOUND_DEATH_HPP
#define GOAT_ENGINE_SOUND_DEATH_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Death : public AudioSource {
    public: Sound_Death(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_DEATH_HPP
