#ifndef GOAT_ENGINE_AUDIOSOURCE_HPP
#define GOAT_ENGINE_AUDIOSOURCE_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {

    enum class AudioSourceType { SAMPLE, MUSIC };

    struct AudioSource : public GameComponent {
        AudioSource(std::string path, AudioSourceType type, uint16_t loops, uint8_t volume, bool queueForPlay, bool active);
        AudioSource(std::string path, AudioSourceType type, uint16_t loops, uint8_t volume, bool active);
        AudioSource(std::string path, AudioSourceType type, bool queueForPlay, bool active);
        AudioSource(std::string path, AudioSourceType type, bool active);
        std::string path;
        const AudioSourceType type;
        bool queueForPlay;
        uint16_t loops; // Amount of loops where 0 means infinite looping
        // GameComponents only encapsulate when necessary by design
        private:
            uint8_t _volume; // 100 is full volume, 0 is muted; all values above 100 are rounded down to 100
        public:
            [[nodiscard]] uint8_t getVolume() const;
            uint8_t setVolume(uint8_t volume);
    };
}

#endif //GOAT_ENGINE_AUDIOSOURCE_HPP
