#include "AudioSource.hpp"

using namespace Engine;

AudioSource::AudioSource(std::string path, AudioSourceType type, bool queueForPlay, bool active) :
    GameComponent(active), type{type}, path{std::move(path)}, queueForPlay{queueForPlay} {
}

AudioSource::AudioSource(std::string path, AudioSourceType type, bool active)
    : AudioSource(std::move(path), type, false, active) {
}
