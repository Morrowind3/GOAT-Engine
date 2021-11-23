//
// Created by MDstu on 21/11/2021.
//

#include "PhysicsApi.hpp"

using namespace  Engine;

void PhysicsApi::CreateWorld() {
    _impl->CreateWorld();
}

void PhysicsApi::DestroyWorld() {
    _impl->DestroyWorld();
}

void PhysicsApi::DestroyBody(b2Body *body) {
    _impl->DestroyBody(body);
}

void PhysicsApi::Update(GameObject &gameObject) {
    _impl->Update(gameObject);
}

void PhysicsApi::Step() {
    _impl->Step();
}