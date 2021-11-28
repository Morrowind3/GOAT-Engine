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

void AudioApi::playSample(const std::string& fileName) {
    _impl->playSample(fileName);
}

void AudioApi::playMusic(const std::string& fileName) {
    _impl->playMusic(fileName);
}

void AudioApi::resetForNextScene() {
    _impl->resetForNextScene();
}
