#ifndef GOAT_ENGINE_SOUND_NAVIGATE_HPP
#define GOAT_ENGINE_SOUND_NAVIGATE_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Navigate: public AudioSource {
    public: Sound_Navigate(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};


#endif //GOAT_ENGINE_SOUND_NAVIGATE_HPP
