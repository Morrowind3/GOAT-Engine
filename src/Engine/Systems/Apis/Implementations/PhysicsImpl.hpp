//
// Created by Mike on 18-11-2021.
//

#ifndef GOAT_ENGINE_PHYSICSIMPL_HPP
#define GOAT_ENGINE_PHYSICSIMPL_HPP

#include "Box2D.h"
#include "../../../API/GameObjects/GameObject.hpp"
#include "Managers/Collision/CollisionManager.hpp"
#include <memory>
#include <iostream>

namespace Engine {
    class PhysicsImpl {
    public:
        PhysicsImpl();

        void CreateBody(std::shared_ptr<GameObject> gameObjectPointer);

        void DestroyWorld();

        void DestroyBody(b2Body *body);

        void Update(std::shared_ptr<GameObject> gameObjectPointer);

        void Step();
    private:
        void AttachBoxCollider(b2Body *rigidBody, double width, double height);
        void AttachCircleCollider(b2Body *rigidBody, double radius);

        b2World _world;
        std::unique_ptr<CollisionManager> _collision;
    };
}

#endif //GOAT_ENGINE_PHYSICSIMPL_HPP
