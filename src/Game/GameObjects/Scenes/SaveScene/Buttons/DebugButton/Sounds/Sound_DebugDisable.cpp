#include "Sound_DebugDisable.hpp"

Sound_DebugDisable::Sound_DebugDisable(uint16_t loops, uint8_t volume, bool queueForPlay, bool active) :
        AudioSource("Sounds/LogOff.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
