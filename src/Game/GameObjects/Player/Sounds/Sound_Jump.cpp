#include "Sound_Jump.hpp"

Sound_Jump::Sound_Jump(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
    AudioSource("Sounds/Jump.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
