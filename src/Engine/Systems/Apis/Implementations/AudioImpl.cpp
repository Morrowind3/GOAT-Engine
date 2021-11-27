#include "AudioImpl.hpp"
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"

using namespace Engine;

AudioImpl::AudioImpl(): _sdlStatus{SDL_Init(SDL_INIT_AUDIO)} {
    // TODO: Adjustable?
    const int audio_rate = 22050;
    const Uint16 audio_format = AUDIO_S16SYS;
    const int audio_channels = 2;
    const int audio_buffers = 4096;

    if (_sdlStatus == 0) _sdlStatus = Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers);
    if (_sdlStatus != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialise audio: %s", Mix_GetError());
        exit(_sdlStatus);
    }
}

void AudioImpl::LoadSample(const std::string& fileName) {
    try {
        _audio->storeSample(fileName);
    } catch (const std::runtime_error& error) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", error.what());
        exit(111);
    }
}

void AudioImpl::LoadMusic(const std::string& fileName) {
    try {
        _audio->storeMusic(fileName);
    } catch (const std::runtime_error& error) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", error.what());
        exit(112);
    }
}

void AudioImpl::PlaySample(const std::string& fileName) {
    const auto& sample = _audio->getSample(fileName);
    Mix_PlayChannel(-1, sample.audio(), 0);
}

void AudioImpl::PlayMusic(const std::string& fileName) {
    const auto& music = _audio->getMusic(fileName);
    Mix_PlayMusic(music.audio(), -1);
}

void AudioImpl::ResetForNextScene() {
    Mix_HaltMusic();
    Mix_HaltChannel(-1);
    _audio->resetForNextScene();
    _audio = std::make_unique<AudioManager>();
}
