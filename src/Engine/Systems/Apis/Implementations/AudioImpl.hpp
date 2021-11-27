#ifndef GOAT_ENGINE_AUDIOIMPL_HPP
#define GOAT_ENGINE_AUDIOIMPL_HPP

#include <string>
#include "../../../NoCopyNoMove.hpp"
#include "Managers/Audio/AudioManager.hpp"

namespace Engine {
    class AudioImpl: NoCopyNoMove {
        public:
            AudioImpl();
            void LoadSample(const std::string& fileName);
            void LoadMusic(const std::string& fileName);
            void PlaySample(const std::string& fileName); // TODO: Loops
            void PlayMusic(const std::string& fileName);
            void ResetForNextScene();
        private:
            int _sdlStatus;
            std::unique_ptr<AudioManager> _audio = std::make_unique<AudioManager>();
        };
}


#endif //GOAT_ENGINE_AUDIOIMPL_HPP
