#ifndef GOAT_ENGINE_OBJECT_TILE_HPP
#define GOAT_ENGINE_OBJECT_TILE_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include <string>
#include <utility>

using namespace Engine;

class Object_Tile : public GameObject {
    public:
        Object_Tile(const std::string& sprite, Transform transform, bool active);
        Object_Tile(const std::string& sprite, const std::shared_ptr<Behavior>& tileBehavior, Transform transform, bool active);
};
#endif //GOAT_ENGINE_OBJECT_TILE_HPP
