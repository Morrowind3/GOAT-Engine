#include "AudioApi.hpp"

using namespace Engine;
using namespace Engine::AudioApi;

void AudioApi::Start() {
    AUDIO_IMPL->Start();
}

void AudioApi::End() {
    AUDIO_IMPL->End();
}

void AudioApi::Play(Mix_Chunk *clip, bool loop, unsigned long times, float volume) {
    AUDIO_IMPL->Play(clip, loop, times, volume);
}

Mix_Chunk* AudioApi::CreateClip(const std::string &clip) {
    return AUDIO_IMPL->CreateClip(clip);
}