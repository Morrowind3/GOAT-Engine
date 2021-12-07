#ifndef GOAT_ENGINE_PHYSICSIMPL_HPP
#define GOAT_ENGINE_PHYSICSIMPL_HPP

#include "Box2D.h"
#include "../../../API/GameObjects/GameObject.hpp"
#include "Managers/Physics/ContactListener.hpp"
#include <memory>
#include <iostream>

namespace Engine {
    class PhysicsImpl {
        public:
            PhysicsImpl();
            void createBody(const GameObject& gameObject);
            void performPhysicsCalculationsForFrame(double deltaTimeInMs);
            void updateGameObjectStateFromPhysicsTick(GameObject& gameObject);
            void runCollisionScripts();
            void resetForNextScene();

        private:
            static void attachBoxCollider(b2Body *rigidBody, double width, double height, double density, bool isSensor);
            static void attachCircleCollider(b2Body *rigidBody, double radius, double density, bool isSensor, b2Vec2 offset);
            std::unique_ptr<b2World> _world;
            std::unique_ptr<ContactListener> _contactListener;
    };
}

#endif //GOAT_ENGINE_PHYSICSIMPL_HPP
