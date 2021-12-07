#ifndef GOAT_ENGINE_GAMECOMPONENT_HPP
#define GOAT_ENGINE_GAMECOMPONENT_HPP

namespace Engine {
    struct GameComponent {
        explicit GameComponent(bool active);
        bool active;
    };
}

#endif //GOAT_ENGINE_GAMECOMPONENT_HPP
