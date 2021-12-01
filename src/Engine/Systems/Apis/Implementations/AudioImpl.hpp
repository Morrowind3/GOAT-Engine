#ifndef GOAT_ENGINE_AUDIOIMPL_HPP
#define GOAT_ENGINE_AUDIOIMPL_HPP

#include <string>
#include "../../../NoCopyNoMove.hpp"
#include "Managers/Audio/AudioManager.hpp"

namespace Engine {
    class AudioImpl: NoCopyNoMove {
        public:
            AudioImpl();
            void loadSample(const std::string& fileName);
            void loadMusic(const std::string& fileName);
            void playSample(const std::string& fileName, uint16_t loops, uint8_t volume);
            void playMusic(const std::string& fileName, uint16_t loops, uint8_t volume);
            void pause();
            void resume();
            void resetForNextScene();
        private:
            int _sdlStatus;
            std::unique_ptr<AudioManager> _audio = std::make_unique<AudioManager>();
        };
}


#endif //GOAT_ENGINE_AUDIOIMPL_HPP
