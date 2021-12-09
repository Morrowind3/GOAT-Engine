#ifndef GOAT_ENGINE_GAMEOBJECT_HPP
#define GOAT_ENGINE_GAMEOBJECT_HPP

#include <map>
#include <memory>

#include "Transform.hpp"
#include "GameComponents/Render/Animator.hpp"
#include "GameComponents/Script/Behavior.hpp"
#include "GameComponents/Audio/AudioSource.hpp"
#include "GameComponents/Render/UI/Button.hpp"
#include "GameComponents/Collision/Collider.hpp"
#include "GameComponents/Collision/RigidBody.hpp"
#include "GameComponents/Collision/BoxCollider.hpp"
#include "GameComponents/Collision/CircleCollider.hpp"
#include "GameComponents/Collision/OvalCollider.hpp"


namespace Engine {
    class ScriptSystem; // Friend class link
    struct GameObject {
        explicit GameObject(Transform transform, bool active);
        bool active;
        // When set to true, this game object will be removed from the scene
        // If the game object is active, the onDestroy scripts will also run
        bool queueForDestruction {false};
        std::map<std::string,bool> tags{}; // True if tag should not be ignored
        [[nodiscard]] bool hasTag(const std::string& tag) const; // Useful method to find an active tag
        Transform transform;
        Collider collider;
        RigidBody rigidBody;
        tsl::ordered_map<std::string,std::shared_ptr<Behavior>> behaviors{};
        std::map<std::string,Text> text{};
        std::map<std::string,Button> buttons{};
        std::map<std::string,Sprite> sprites{};
        std::map<std::string,Animator> animators{};
        std::map<std::string,AudioSource> audioSources{};
        private:
            friend class Engine::ScriptSystem;
            bool _destroyNextTick {false}; // Set by the script system so that onDestroy code runs properly
    };
}

#endif //GOAT_ENGINE_GAMEOBJECT_HPP