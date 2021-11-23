//
// Created by MDstu on 22/11/2021.
//

#include "CollisionSystem.hpp"

using namespace Engine;

CollisionSystem::CollisionSystem(const Scene *scene): System(scene), _api{PhysicsApi::getInstance()} {

}

void CollisionSystem::OnInit() {
    _api.CreateWorld();
}

void CollisionSystem::OnUpdate(double deltaTime) {
//    _api.Step();
}

void CollisionSystem::OnDestroy() {

}