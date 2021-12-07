#include "Sound_WalkAlt.hpp"

Sound_WalkAlt::Sound_WalkAlt(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
    AudioSource("Sounds/WalkAlt.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
