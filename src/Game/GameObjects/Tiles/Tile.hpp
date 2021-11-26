//
// Created by Stijn van Loon on 22-11-2021.
//

#ifndef GOAT_ENGINE_TILE_HPP
#define GOAT_ENGINE_TILE_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include <string>
#include <utility>

using namespace Engine;

namespace TILE {
    const std::string SPRITE = "Sprite";
}

class Tile : public GameObject {
public:
    explicit Tile(const std::string& sprite, const std::shared_ptr<Behavior>& tileBehavior, std::string tag, Transform transform, bool active)
            : GameObject(transform, active), tag(std::move(tag)) {
        sprites.insert(std::make_pair(TILE::SPRITE, Sprite{sprite, true}));
        behaviors.push_back(tileBehavior);
        rigidBody = RigidBody(5.0f, 5.0f, BodyType::STATIC, true);
        collider = BoxCollider(105,105,true);

    };
    std::string tag;
};

#endif //GOAT_ENGINE_TILE_HPP
