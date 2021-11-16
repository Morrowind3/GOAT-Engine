#pragma once

#include <map>
#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"

namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        Transform transform;
        std::vector<Behavior> behaviors;
        std::map<std::string,Sprite> sprites;
        Sprite* activeSprite = nullptr;
    };
}
