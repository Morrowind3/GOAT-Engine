#include "Sample.hpp"

using namespace Engine;

Sample::Sample(Mix_Chunk* audio): _audio{audio} {
}

Mix_Chunk* Sample::audio() const {
    return _audio;
}
