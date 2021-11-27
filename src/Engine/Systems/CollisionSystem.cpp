#include "CollisionSystem.hpp"

using namespace Engine;

void CollisionSystem::OnLaunchEngine() {
    _api = &PhysicsApi::getInstance();
}

void CollisionSystem::OnLoadScene(std::shared_ptr<Scene> scene) {
    _scene = scene;
    for (auto& gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api->CreateBody(gameObject);
        }
    }
}

void CollisionSystem::OnFrameTick(double deltaTime) {
    _api->Step();
    for (auto &gameObject: _scene->gameObjects) {
        if (gameObject->rigidBody.active && gameObject->rigidBody.bodyType == BodyType::DYNAMIC) {
            _api->Update(gameObject);
        }
    }
}

void CollisionSystem::OnCloseEngine() {
    // Empty
}
