#pragma once

#include <vector>

#include "GameObjects/GameObject.hpp"

struct Scene {
    explicit Scene(std::vector<GameObject>& gameObjects);
    std::vector<GameObject>& _gameObjects;
};
