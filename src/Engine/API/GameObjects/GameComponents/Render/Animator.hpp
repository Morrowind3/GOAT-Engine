#ifndef GOAT_ENGINE_ANIMATOR_HPP
#define GOAT_ENGINE_ANIMATOR_HPP

#include <vector>
#include "Sprite.hpp"

namespace Engine {
    class RenderingSystem; // Friend class link
    struct Animator : public GameComponent {
        Animator(uint16_t fps, bool loop, bool active);
        std::vector<Sprite*> sprites{};
        uint16_t fps;
        bool loop;
    };
}

#endif //GOAT_ENGINE_ANIMATOR_HPP
