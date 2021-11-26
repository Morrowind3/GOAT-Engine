//
// Created by MDstu on 21/11/2021.
//

#include "PhysicsApi.hpp"

using namespace  Engine;

void PhysicsApi::CreateBody(std::shared_ptr<GameObject> gameObjectPointer)  {
    physics.CreateBody(gameObjectPointer);
}

void PhysicsApi::DestroyWorld() {
    physics.DestroyWorld();
}

void PhysicsApi::DestroyBody(b2Body *body) {
    physics.DestroyBody(body);
}

void PhysicsApi::Update(std::shared_ptr<GameObject> gameObjectPointer) {
    physics.Update(gameObjectPointer);
}

void PhysicsApi::Step() {
    physics.Step();
}