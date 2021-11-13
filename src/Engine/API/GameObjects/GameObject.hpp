#pragma once

#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Sprite.hpp"

struct GameObject {
    Transform transform;
    Sprite sprite;
    const std::vector<GameComponent>& _gameComponents; // TODO: Research object splicing
    GameObject(Transform transform, Sprite sprite, const std::vector<GameComponent>& gameComponents);
};