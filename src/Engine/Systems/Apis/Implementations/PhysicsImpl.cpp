//
// Created by Mike on 18-11-2021.
//

#include "PhysicsImpl.hpp"

using namespace Engine;

PhysicsImpl::PhysicsImpl() : _world{b2World{b2Vec2{0.0f, -10.0f}}} {

}

void PhysicsImpl::CreateWorld() {
//    b2World test {b2Vec2(0.0f, -10.0f)};
//    test.Step(1.0f / 60.0f, 8,6);
//
//    _world = test;
}

void PhysicsImpl::DestroyWorld() {

}

void PhysicsImpl::DestroyBody(b2Body *body) {

}

void PhysicsImpl::Update(GameObject &gameObject) {

}

void PhysicsImpl::Step() {
    _world.Step(1.0f / 60.0f, 8,6);
}
