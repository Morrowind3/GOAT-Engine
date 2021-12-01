#ifndef GOAT_ENGINE_SOUND_OOF_HPP
#define GOAT_ENGINE_SOUND_OOF_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Oof : public AudioSource {
    public: Sound_Oof(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_OOF_HPP
