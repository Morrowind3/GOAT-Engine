#include "Sound_Oof.hpp"

Sound_Oof::Sound_Oof(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
        AudioSource("Sounds/Oof.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
