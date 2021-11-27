#ifndef GOAT_ENGINE_GAMEOBJECT_HPP
#define GOAT_ENGINE_GAMEOBJECT_HPP

#include <map>
#include <memory>

#include "GameComponents/GameComponent.hpp"
#include "Transform.hpp"
#include "GameComponents/Render/Sprite.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/Render/UI/Button.hpp"
#include "GameComponents/Collision/Collider.hpp"
#include "GameComponents/Collision/RigidBody.hpp"


namespace Engine {
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        Transform transform;
        Collider collider;
        RigidBody rigidBody;
        tsl::ordered_map<std::string,std::shared_ptr<Behavior>> behaviors{};
        std::map<std::string,Text> text{};
        std::map<std::string,Button> buttons{};
        std::map<std::string,Sprite> sprites{};
        std::map<std::string,AudioSource> audioSources{};
    };
}

#endif //GOAT_ENGINE_GAMEOBJECT_HPP