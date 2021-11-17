#pragma once

#include <map>
#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/UI/Font.hpp"

namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        // Active data
        bool active;
        Transform transform;
        Sprite* activeSprite = nullptr;
        // Passive data
        std::vector<Behavior> behaviors;
        std::vector<Font> fonts;
        std::map<std::string,Sprite> sprites;
        std::map<std::string,AudioSource> audioSources;
    };
}
