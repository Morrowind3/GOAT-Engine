//
// Created by MDstu on 14/11/2021.
//

#include "AudioImpl.hpp"
#include <iostream>
using namespace Engine;

void AudioImpl::Start() {
    SDL_Init(SDL_INIT_AUDIO);

    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;

    if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialise audio: %s", Mix_GetError());
        exit(-1);
    }
}

void AudioImpl::End() {
    SDL_Quit();
}

void AudioImpl::Play(Mix_Chunk *clip, bool loop, unsigned long times, float volume) {
    if(clip != nullptr) {
        if (loop) {
            // 'loops: -1' means infinitely loops
            Mix_PlayChannel(-1, clip, -1);
        } else {
            Mix_PlayChannel(-1, clip, times);
        }
    }else{
        std::cerr << Mix_GetError() << ": " << std::endl;
    }
}

Mix_Chunk* AudioImpl::CreateClip(const std::string &clip) {
    return Mix_LoadWAV(clip.c_str());
}