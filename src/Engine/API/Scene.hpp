#pragma once

#include <vector>

#include "GameObjects/GameObject.hpp"

namespace Engine {
    class Scene {
    public:
        explicit Scene(std::string name);
        std::string _name;
        std::vector<GameObject*> _gameObjects{};
    };
}
