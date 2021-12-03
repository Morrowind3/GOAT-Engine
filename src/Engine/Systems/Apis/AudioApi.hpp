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
            void loadSample(const std::string& fileName);
            void loadMusic(const std::string& fileName);
            void playSample(const std::string& fileName, uint16_t loops, uint8_t volume);
            void playMusic(const std::string& fileName, uint16_t loops, uint8_t volume);
            void pause();
            void resume();
            void resetForNextScene();
        private:
            AudioApi();
            std::unique_ptr<AudioImpl> _impl;
    };
}


#endif //GOAT_ENGINE_AUDIOAPI_HPP
