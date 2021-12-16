#ifndef GOAT_ENGINE_MUSIC_WOODWHISTLES_HPP
#define GOAT_ENGINE_MUSIC_WOODWHISTLES_HPP

#include "../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Music_WoodWhistles: public AudioSource {
    public: Music_WoodWhistles(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};


#endif //GOAT_ENGINE_MUSIC_WOODWHISTLES_HPP
