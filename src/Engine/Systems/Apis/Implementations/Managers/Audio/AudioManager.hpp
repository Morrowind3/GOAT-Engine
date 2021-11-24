#ifndef GOAT_ENGINE_AUDIOMANAGER_HPP
#define GOAT_ENGINE_AUDIOMANAGER_HPP

#include "SDL_mixer.h"
#include "Sample.hpp"
#include "Music.hpp"

#include <map>
#include <memory>
#include <string>

namespace Engine {
    class AudioManager {
        public:
            AudioManager();
            void storeSample(const std::string& fileName);
            void storeMusic(const std::string& fileName);
            [[nodiscard]] const Sample& getSample(const std::string& fileName) const;
            [[nodiscard]] const Music& getMusic(const std::string& fileName) const;
            [[maybe_unused]] void removeSample(const std::string& fileName);
            [[maybe_unused]] void removeMusic(const std::string& fileName);
        private:
            std::unique_ptr<std::map<std::string,Sample>> _samples;
            std::unique_ptr<std::map<std::string,Music>> _music;
    };
}

#endif //GOAT_ENGINE_AUDIOMANAGER_HPP
