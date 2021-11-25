//
// Created by MDstu on 22/11/2021.
//

#include "CollisionSystem.hpp"

using namespace Engine;

CollisionSystem::CollisionSystem(const Scene *scene): System(scene), _api(PhysicsApi::PhysicsApi::getInstance()) {

}

void CollisionSystem::OnInit() {
    for (auto &gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api.CreateBody(gameObject->rigidBody, gameObject->transform);
        }
    }
}
void CollisionSystem::OnUpdate(double deltaTime) {
    _api.Step();

    for(auto &gameObject : _scene->gameObjects){
        if(gameObject->rigidBody.active){
            _api.Update(gameObject->rigidBody, gameObject->transform);
        }
    }
}

void CollisionSystem::OnDestroy() {

}