#pragma once

namespace Engine {
    struct GameComponent {
        explicit GameComponent(bool active);
        bool active;
    };
}
