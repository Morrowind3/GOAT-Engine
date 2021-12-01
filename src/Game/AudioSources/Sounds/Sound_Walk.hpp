#ifndef GOAT_ENGINE_SOUND_WALK_HPP
#define GOAT_ENGINE_SOUND_WALK_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Sound_Walk : public AudioSource {
    public: Sound_Walk(uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
};


#endif //GOAT_ENGINE_SOUND_WALK_HPP
