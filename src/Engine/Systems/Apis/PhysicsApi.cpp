//
// Created by MDstu on 21/11/2021.
//

#include "PhysicsApi.hpp"

using namespace  Engine;

void PhysicsApi::CreateBody(GameObject &gameObject)  {
//    physics.CreateBody(rigidBody, transform);
}

void PhysicsApi::DestroyWorld() {
    physics.DestroyWorld();
}

void PhysicsApi::DestroyBody(b2Body *body) {
    physics.DestroyBody(body);
}

void PhysicsApi::Update(RigidBody &rigidBody, Transform &transform) {
    physics.Update(rigidBody, transform);
}

void PhysicsApi::Step() {
    physics.Step();
}