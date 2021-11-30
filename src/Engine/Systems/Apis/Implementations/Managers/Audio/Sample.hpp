#ifndef GOAT_ENGINE_SAMPLE_HPP
#define GOAT_ENGINE_SAMPLE_HPP

#include <SDL_mixer.h>

namespace Engine {
    class Sample {
        public:
            explicit Sample(Mix_Chunk* audio);
            [[nodiscard]] Mix_Chunk* audio() const;
        private:
            Mix_Chunk* _audio;
    };
}



#endif //GOAT_ENGINE_SAMPLE_HPP
