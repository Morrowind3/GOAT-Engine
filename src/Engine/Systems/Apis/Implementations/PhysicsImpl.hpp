#ifndef GOAT_ENGINE_PHYSICSIMPL_HPP
#define GOAT_ENGINE_PHYSICSIMPL_HPP

#include "Box2D.h"
#include "../../../API/GameObjects/GameObject.hpp"
#include <memory>
#include <iostream>

namespace Engine {
    class PhysicsImpl {
        public:
            PhysicsImpl() = default;
            void CreateBody(const GameObject& gameObject);
            void PerformPhysicsCalculationsForFrame();
            void UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject);
            void ResetForNextScene();
        private:
            void AttachBoxCollider(b2Body *rigidBody, double width, double height, double density);
            void AttachCircleCollider(b2Body *rigidBody, double radius, double density);
            std::unique_ptr<b2World> _world = std::make_unique<b2World>(b2Vec2{0.0f, 10.0f});
    };
}

#endif //GOAT_ENGINE_PHYSICSIMPL_HPP
