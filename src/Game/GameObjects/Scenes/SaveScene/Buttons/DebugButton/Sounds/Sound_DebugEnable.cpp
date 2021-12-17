#include "Sound_DebugEnable.hpp"

Sound_DebugEnable::Sound_DebugEnable(uint16_t loops, uint8_t volume, bool queueForPlay, bool active) :
        AudioSource("Sounds/LogOn.ogg",AudioSourceType::SAMPLE, loops, volume, queueForPlay, active) {
}
