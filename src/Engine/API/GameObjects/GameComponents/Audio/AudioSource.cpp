#include "AudioSource.hpp"

using namespace Engine;

AudioSource::AudioSource(std::string path, AudioSourceType type, uint16_t loops, uint8_t volume, bool queueForPlay, bool active):
    GameComponent(active), type{type}, path{std::move(path)}, loops{loops}, _volume{setVolume(volume)}, queueForPlay{queueForPlay} {
}

AudioSource::AudioSource(std::string path, AudioSourceType type, uint16_t loops, uint8_t volume, bool active):
    AudioSource(std::move(path), type, loops, volume, false, active) {
}

// Music loops indefinitely (0) and samples play once (1)
static uint16_t defaultLoopValue(AudioSourceType type) {
    return type == AudioSourceType::MUSIC ? 0 : 1;
}

AudioSource::AudioSource(std::string path, AudioSourceType type, uint8_t volume, bool queueForPlay, bool active):
        AudioSource(std::move(path), type, defaultLoopValue(type), volume, queueForPlay, active) {
}

AudioSource::AudioSource(std::string path, AudioSourceType type, bool queueForPlay, bool active) :
    AudioSource(std::move(path), type, defaultLoopValue(type), 100, queueForPlay, active) {
}

AudioSource::AudioSource(std::string path, AudioSourceType type, bool active):
    AudioSource(std::move(path), type, defaultLoopValue(type), 100, false, active) {
}

uint8_t AudioSource::getVolume() const {
    return _volume;
}

uint8_t AudioSource::setVolume(uint8_t volume) {
    _volume = volume <= 100 ? volume : 100;
    return getVolume();
}
