#ifndef GOAT_ENGINE_GAMEOBJECT_HPP
#define GOAT_ENGINE_GAMEOBJECT_HPP

#include <map>
#include <memory>
#include <vector>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/Render/UI/Button.hpp"

namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        Transform transform;
        std::vector<std::shared_ptr<Behavior>> behaviors{}; // TODO: Convert to map
        // TODO: Merge text and button into UIObject?
        std::map<std::string,Text> text{};
        std::map<std::string,Button> buttons{};
        std::map<std::string,Sprite> sprites{};
        std::map<std::string,AudioSource> audioSources{};
    };
}

#endif //GOAT_ENGINE_GAMEOBJECT_HPP