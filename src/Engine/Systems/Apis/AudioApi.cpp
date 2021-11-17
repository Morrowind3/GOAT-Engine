#include "AudioApi.hpp"

using namespace Engine;

AudioApi::AudioApi(): _impl{std::make_unique<AudioImpl>()} {

}

void AudioApi::LoadSample(const std::string& fileName) {
    _impl->LoadSample(fileName);
}

void AudioApi::LoadMusic(const std::string& fileName) {
    _impl->LoadMusic(fileName);
}

void AudioApi::PlaySample(const std::string& fileName) {
    _impl->PlaySample(fileName);
}

void AudioApi::PlayMusic(const std::string& fileName) {
    _impl->PlayMusic(fileName);
}
