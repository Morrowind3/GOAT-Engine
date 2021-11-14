#pragma once

#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Script.hpp"

namespace Engine {
    struct GameObject {
        GameObject(Transform transform, Sprite sprite, bool active);
        bool active;
        // TODO: Find a better way to store components than specifying each possible component type?
        std::vector<Script*> scripts;
        Transform transform;
        Sprite sprite;
    };
}
