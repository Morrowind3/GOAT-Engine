#pragma once

#include <vector>

#include "GameObjects/GameObject.hpp"

namespace Engine {
    class Scene {
    public:
        explicit Scene(std::string name);
        std::string name;
        std::vector<std::shared_ptr<GameObject>> gameObjects{};
    };
}
