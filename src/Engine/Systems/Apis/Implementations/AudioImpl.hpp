#ifndef GOAT_ENGINE_AUDIOIMPL_HPP
#define GOAT_ENGINE_AUDIOIMPL_HPP

#include <string>
#include "SDL.h"
#include "SDL_mixer.h"

namespace Engine {
    class AudioImpl {
    public:
        void Start();
        void End();
        void Play(Mix_Chunk *clip, bool loop, unsigned long times, float volume);
        Mix_Chunk *CreateClip(const std::string &clip);
    };
}


#endif //GOAT_ENGINE_AUDIOIMPL_HPP
