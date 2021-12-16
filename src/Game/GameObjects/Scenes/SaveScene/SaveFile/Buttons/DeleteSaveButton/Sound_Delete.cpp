#include "Sound_Delete.hpp"

Sound_Delete::Sound_Delete(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
        AudioSource("Sounds/Delete.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
