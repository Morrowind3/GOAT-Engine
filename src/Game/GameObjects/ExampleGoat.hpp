#ifndef GOAT_ENGINE_EXAMPLEGOAT_HPP
#define GOAT_ENGINE_EXAMPLEGOAT_HPP

#include "../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
#include "../Behaviors/TestGoatBehavior.hpp"

using namespace Engine;

class ExampleGoat : public GameObject {
    public:
        explicit ExampleGoat(Transform transform);
    private:
        std::unique_ptr<TestGoatBehavior> _goatBehavior;
};

#endif //GOAT_ENGINE_EXAMPLEGOAT_HPP