#ifndef GOAT_ENGINE_MUSIC_SMOOTHGROOVE_HPP
#define GOAT_ENGINE_MUSIC_SMOOTHGROOVE_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Music_SmoothGroove: public AudioSource {
    public: Music_SmoothGroove(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};

#endif //GOAT_ENGINE_MUSIC_SMOOTHGROOVE_HPP
