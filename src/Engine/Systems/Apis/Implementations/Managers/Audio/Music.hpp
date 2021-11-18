#ifndef GOAT_ENGINE_MUSIC_HPP
#define GOAT_ENGINE_MUSIC_HPP

#include <SDL_mixer.h>

namespace Engine {
    class Music {
        public:
            explicit Music(Mix_Music* audio);
            [[nodiscard]] Mix_Music* audio() const;
        private:
            Mix_Music* _audio;
    };
}

#endif //GOAT_ENGINE_MUSIC_HPP
