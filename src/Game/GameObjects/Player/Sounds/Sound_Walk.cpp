#include "Sound_Walk.hpp"

Sound_Walk::Sound_Walk(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
    AudioSource("Sounds/Walk.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay ,active) {
}
