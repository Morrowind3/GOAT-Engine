#include "Music_WoodWhistles.hpp"

Music_WoodWhistles::Music_WoodWhistles(uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
        AudioSource("Music/Wood_Whistles.mp3", AudioSourceType::MUSIC, loops, volume, queueForPlay, active) {
}
