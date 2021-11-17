#ifndef GOAT_ENGINE_AUDIOAPI_HPP
#define GOAT_ENGINE_AUDIOAPI_HPP

#include "SDL.h"
#include "SDL_mixer.h"
#include <string>
#include <memory>
#include "Implementations/AudioImpl.hpp"

namespace Engine {
    class AudioApi: NoCopyNoMove {
        public:
            static AudioApi& getInstance() {
                static AudioApi instance{};
                return instance;
            }
            void LoadSample(const std::string& fileName);
            void LoadMusic(const std::string& fileName);
            void PlaySample(const std::string& fileName);
            void PlayMusic(const std::string& fileName);
        private:
            AudioApi();
            std::unique_ptr<AudioImpl> _impl;
    };
}


#endif //GOAT_ENGINE_AUDIOAPI_HPP
