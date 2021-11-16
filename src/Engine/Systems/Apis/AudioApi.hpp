#ifndef GOAT_ENGINE_AUDIOAPI_HPP
#define GOAT_ENGINE_AUDIOAPI_HPP

#include "SDL.h"
#include "SDL_mixer.h"
#include <string>
#include <memory>
#include "Implementations/AudioImpl.hpp"

namespace Engine::AudioApi {
    void Play(Mix_Chunk *clip, bool loop, unsigned long times, float volume);
    Mix_Chunk* CreateClip(const std::string &clip);
    void Start();
    void End();
    static std::unique_ptr<AudioImpl> AUDIO_IMPL;
}


#endif //GOAT_ENGINE_AUDIOAPI_HPP
