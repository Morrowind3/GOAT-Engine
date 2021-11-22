#pragma once

#include <map>
#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/Render/UI/Text.hpp"

namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        Transform transform;
        std::vector<Behavior> behaviors; // TODO: Convert to map
        std::map<std::string,Text> text;
        std::map<std::string,Sprite> sprites;
        std::map<std::string,AudioSource> audioSources;
    };
}
