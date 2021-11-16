#ifndef GOAT_ENGINE_GOAT_HPP
#define GOAT_ENGINE_GOAT_HPP

#include "../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../Behaviors/GoatBehavior.hpp"

using namespace Engine;

class Goat : public GameObject {
    public:
        explicit Goat(Transform transform);
    private:
        std::unique_ptr<GoatBehavior> _goatBehavior;
};

#endif //GOAT_ENGINE_GOAT_HPP