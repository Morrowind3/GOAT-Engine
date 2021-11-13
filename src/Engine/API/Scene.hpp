#pragma once

#include <vector>

#include "GameObjects/GameObject.hpp"

namespace Engine {
    struct Scene {
        explicit Scene(std::vector<GameObject>& gameObjects);
        std::vector<GameObject>& gameObjects;
    };
}
