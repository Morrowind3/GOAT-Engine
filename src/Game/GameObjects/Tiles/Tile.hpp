#ifndef GOAT_ENGINE_TILE_HPP
#define GOAT_ENGINE_TILE_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include <string>
#include <utility>

using namespace Engine;

class Tile : public GameObject {
    public:
        Tile(const std::string& sprite, const std::shared_ptr<Behavior>& tileBehavior, std::string tag, Transform transform, bool active);
        std::string tag;
};

#endif //GOAT_ENGINE_TILE_HPP
