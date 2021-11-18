//
// Created by Mike on 18-11-2021.
//

#include "PhysicsImpl.hpp"

void PhysicsImpl::CreateWorld() {
    b2Vec2 gravity(0.0f, -10.0f);
    world = std::make_unique<b2World>(gravity);
}

void PhysicsImpl::DestroyWorld() {
    world.reset();
}

void PhysicsImpl::DestroyBody(b2Body *body) {
    world.get()->DestroyBody(body);
}
