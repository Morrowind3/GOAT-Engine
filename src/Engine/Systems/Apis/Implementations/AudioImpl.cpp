#include "AudioImpl.hpp"
#include "SDL.h"
#include "SDL_mixer.h"

using namespace Engine;

AudioImpl::AudioImpl(): _sdlStatus{SDL_Init(SDL_INIT_AUDIO)} {
    const int audio_rate = 22050;
    const Uint16 audio_format = AUDIO_S16SYS;
    const int audio_channels = 2;
    const int audio_buffers = 4096;

    if (_sdlStatus == 0) _sdlStatus = Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers);
    if (_sdlStatus != 0) {
        _debug.log(std::string{Mix_GetError()});
        exit(_sdlStatus);
    }
}

void AudioImpl::loadSample(const std::string& fileName) {
    try {
        _audio->storeSample(fileName);
    } catch (const std::runtime_error& error) {
        _debug.log(error.what());
        exit(111);
    }
}

void AudioImpl::loadMusic(const std::string& fileName) {
    try {
        _audio->storeMusic(fileName);
    } catch (const std::runtime_error& error) {
        _debug.log(error.what());
        exit(112);
    }
}

static int sdlLoops(uint16_t componentLoops) {
    return componentLoops-1;
}

static int sdlVolume(uint8_t componentVolume) {
    return componentVolume*1.28;
}

void AudioImpl::playSample(const std::string& fileName, uint16_t loops, uint8_t volume) {
    const auto& sample = _audio->getSample(fileName);
    int channelNumber = Mix_PlayChannel(-1, sample.audio(), sdlLoops(loops));
    Mix_Volume(channelNumber, sdlVolume(volume));
}

void AudioImpl::playMusic(const std::string& fileName, uint16_t loops, uint8_t volume) {
    const auto& music = _audio->getMusic(fileName);
    Mix_PlayMusic(music.audio(), sdlLoops(loops));
    Mix_VolumeMusic(sdlVolume(volume));
}

void AudioImpl::resetForNextScene() {
    Mix_HaltMusic();
    Mix_HaltChannel(-1);
    _audio->resetForNextScene();
    _audio = std::make_unique<AudioManager>();
}

void AudioImpl::pause() {
    Mix_PauseMusic();
}

void AudioImpl::resume() {
    Mix_ResumeMusic();
}
