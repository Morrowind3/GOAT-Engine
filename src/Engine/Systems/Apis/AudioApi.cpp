#include "AudioApi.hpp"

using namespace Engine;

AudioApi::AudioApi(): _impl{std::make_unique<AudioImpl>()} {
}

void AudioApi::loadSample(const std::string& fileName) {
    _impl->loadSample(fileName);
}

void AudioApi::loadMusic(const std::string& fileName) {
    _impl->loadMusic(fileName);
}

void AudioApi::playSample(const std::string& fileName, uint16_t loops, uint8_t volume) {
    _impl->playSample(fileName, loops, volume);
}

void AudioApi::playMusic(const std::string& fileName, uint16_t loops, uint8_t volume) {
    _impl->playMusic(fileName, loops, volume);
}

void AudioApi::resetForNextScene() {
    _impl->resetForNextScene();
}

void AudioApi::pause() {
    _impl->pause();
}

void AudioApi::resume() {
    _impl->resume();
}
