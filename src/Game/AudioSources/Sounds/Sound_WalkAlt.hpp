#ifndef GOAT_ENGINE_SOUND_WALKALT_HPP
#define GOAT_ENGINE_SOUND_WALKALT_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_WalkAlt : public AudioSource {
    public: Sound_WalkAlt(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_WALKALT_HPP
