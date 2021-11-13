#pragma once

#include <memory>
#include <map>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"

namespace Engine {
    struct GameObject {
        GameObject(Transform transform, Sprite sprite, bool active);
        bool active;
        // TODO: Find a better way to store components than this
        Transform transform;
        Sprite sprite;
    };
}
