//
// Created by Mike on 18-11-2021.
//

#ifndef GOAT_ENGINE_PHYSICSIMPL_HPP
#define GOAT_ENGINE_PHYSICSIMPL_HPP

#include "box2d.h"
#include "../../../API/GameObjects/GameObject.hpp"
#include <memory>

namespace  Engine {
    class PhysicsImpl {
    public:
        void CreateWorld();

        void DestroyWorld();

        void DestroyBody(b2Body *body);

        void AttachCollision(GameObject &gameObject);

    private:
        std::unique_ptr<b2World> world;
    };
}

#endif //GOAT_ENGINE_PHYSICSIMPL_HPP
