#ifndef GOAT_ENGINE_PHYSICSIMPL_HPP
#define GOAT_ENGINE_PHYSICSIMPL_HPP

#include "Box2D.h"
#include "../../../API/GameObjects/GameObject.hpp"
#include "Managers/Physics/ContactListener.hpp"
#include "../../../Utilities/Debug.hpp"
#include "../../../Utilities/EngineCalls.hpp"
#include <memory>
#include <iostream>

namespace Engine {
    class PhysicsImpl {
        public:
            PhysicsImpl();
            void createBody(const GameObject& gameObject);
            void performPhysicsCalculationsForFrame();
            void updateGameObjectStateFromPhysicsTick(GameObject& gameObject);
            void runCollisionScripts();
            void resetForNextScene();

        private:
            static void attachBoxCollider(b2Body *rigidBody, double width, double height, double density, bool isSensor, double friction, double restitution );
            static void attachCircleCollider(b2Body *rigidBody, double radius, double density, bool isSensor, b2Vec2 offset, double friction, double restitution );
            static void attachOvalCollider(b2Body *rigidBody, double radius, double density, b2Vec2 offSet, double friction, double restitution );
            std::unique_ptr<b2World> _world;
            std::unique_ptr<ContactListener> _contactListener;
            Debug& _debug = Debug::getInstance();
            EngineCalls& _engineCalls = EngineCalls::getInstance();
    };
}

#endif //GOAT_ENGINE_PHYSICSIMPL_HPP
