#include "Music_SmoothGroove.hpp"

Music_SmoothGroove::Music_SmoothGroove(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
 AudioSource("Music/Smooth_Groove.mp3", AudioSourceType::MUSIC, loops, volume, queueForPlay, active) {
}
