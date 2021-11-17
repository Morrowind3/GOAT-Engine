#ifndef GOAT_ENGINE_AUDIOSOURCE_HPP
#define GOAT_ENGINE_AUDIOSOURCE_HPP

#include "../GameComponent.hpp"
#include <string>

namespace Engine {

    enum class AudioSourceType { SAMPLE, MUSIC };

    struct AudioSource : public GameComponent {
        AudioSource(std::string path, AudioSourceType type, bool queueForPlay, bool active);
        AudioSource(std::string path, AudioSourceType type, bool active);
        std::string path;
        AudioSourceType type;
        bool queueForPlay;
    };
}

#endif //GOAT_ENGINE_AUDIOSOURCE_HPP
