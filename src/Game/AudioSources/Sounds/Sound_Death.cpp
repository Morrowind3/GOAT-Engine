#include "Sound_Death.hpp"

Sound_Death::Sound_Death(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
        AudioSource("Sounds/Death.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
