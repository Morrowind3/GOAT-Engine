#ifndef GOAT_ENGINE_AUDIOIMPL_HPP
#define GOAT_ENGINE_AUDIOIMPL_HPP

#include <string>
#include "../../../NoCopyNoMove.hpp"
#include "Managers/Audio/AudioManager.hpp"

namespace Engine {
    class AudioImpl: NoCopyNoMove {
        public:
            AudioImpl();
            ~AudioImpl() override;
            void LoadSample(const std::string& fileName);
            void LoadMusic(const std::string& fileName);
            void PlaySample(const std::string& fileName);
            void PlayMusic(const std::string& fileName);

        private:
            int _sdlStatus;
            std::unique_ptr<AudioManager> _audio;
        };
}


#endif //GOAT_ENGINE_AUDIOIMPL_HPP
