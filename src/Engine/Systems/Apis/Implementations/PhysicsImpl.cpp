//
// Created by Mike on 18-11-2021.
//

#include <iostream>
#include "PhysicsImpl.hpp"

using namespace Engine;

void PhysicsImpl::CreateWorld() {
    b2Vec2 gravity(0.0f, -10.0f);
}

void PhysicsImpl::DestroyWorld() {

}


void PhysicsImpl::DestroyBody(b2Body *body) {

}

void PhysicsImpl::Update(GameObject &gameObject) {

}

void PhysicsImpl::Step() {
//    double timeStep = 1.0f / 60.0f;
//    int32 velocityIterations = 10;
//    int32 positionIterations = 8;
//    world->Step(timeStep, velocityIterations, positionIterations);

    std::cout << "step" <<std::endl;
}
