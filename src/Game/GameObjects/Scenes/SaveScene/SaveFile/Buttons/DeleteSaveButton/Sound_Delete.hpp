#ifndef GOAT_ENGINE_SOUND_DELETE_HPP
#define GOAT_ENGINE_SOUND_DELETE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Delete: public AudioSource {
    public: Sound_Delete(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_SOUND_DELETE_HPP
