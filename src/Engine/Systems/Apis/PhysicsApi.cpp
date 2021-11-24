//
// Created by MDstu on 21/11/2021.
//

#include "PhysicsApi.hpp"

using namespace  Engine;

void PhysicsApi::CreateWorld() {
    physics.CreateWorld();
}

void PhysicsApi::DestroyWorld() {
    physics.DestroyWorld();
}

void PhysicsApi::DestroyBody(b2Body *body) {
    physics.DestroyBody(body);
}

void PhysicsApi::Update(GameObject &gameObject) {
    physics.Update(gameObject);
}

void PhysicsApi::Step() {
    physics.Step();
}