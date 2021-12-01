#ifndef GOAT_ENGINE_SOUND_JUMP_HPP
#define GOAT_ENGINE_SOUND_JUMP_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Jump : public AudioSource {
    public: Sound_Jump(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_JUMP_HPP
