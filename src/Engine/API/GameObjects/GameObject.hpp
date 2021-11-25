#pragma once

#include <map>
#include <memory>
#include <vector>
#include <any>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/Render/UI/Text.hpp"
#include "GameComponents/Collision/Collider.hpp"
#include "GameComponents/Collision/RigidBody.hpp."

namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        Transform transform;
        Collider collider;
        RigidBody rigidBody;
        std::vector<std::shared_ptr<Behavior>> behaviors; // TODO: Convert to map
        std::map<std::string,Text> text;
        std::map<std::string,Sprite> sprites;
        std::map<std::string,AudioSource> audioSources;
    };
}
