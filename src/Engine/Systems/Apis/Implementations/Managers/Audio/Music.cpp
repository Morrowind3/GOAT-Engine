#include "Music.hpp"

using namespace Engine;

Music::Music(Mix_Music* audio): _audio{audio} {
}

Mix_Music* Music::audio() const {
    return _audio;
}
