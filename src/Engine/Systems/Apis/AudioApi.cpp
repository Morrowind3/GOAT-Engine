//
// Created by MDstu on 14/11/2021.
//

#include "AudioApi.hpp"

using namespace Engine;
using namespace Engine::AudioApi;

void AudioApi::Start() {
    AUDIO_IMPL.get()->Start();
}

void AudioApi::End() {
    AUDIO_IMPL.get()->End();
}

void AudioApi::Play(Mix_Chunk *clip, bool loop, unsigned long times, float volume) {
    AUDIO_IMPL.get()->Play(clip, loop, times, volume);
}

void AudioApi::CreateClip(const std::string &clip) {
    AUDIO_IMPL.get()->CreateClip(clip);
}