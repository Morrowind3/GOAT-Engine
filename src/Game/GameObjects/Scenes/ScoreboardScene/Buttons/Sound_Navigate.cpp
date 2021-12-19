#include "Sound_Navigate.hpp"

Sound_Navigate::Sound_Navigate(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
        AudioSource("Sounds/Navigate.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
