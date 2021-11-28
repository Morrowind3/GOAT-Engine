#include "CollisionSystem.hpp"

using namespace Engine;

void CollisionSystem::OnLaunchEngine() {
    _debug.log("Collision system launch");
    _api = &PhysicsApi::getInstance();
}

void CollisionSystem::OnLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Collision system load");
    _api->ResetForNextScene();
    _scene = scene;
    for (auto& gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api->CreateBody(*gameObject);
        }
    }
}

void CollisionSystem::OnFrameTick(double deltaTime) {
    _api->PerformPhysicsCalculationsForFrame();
    for (auto &gameObject: _scene->gameObjects) {
        if (gameObject->rigidBody.active && gameObject->rigidBody.bodyType == BodyType::DYNAMIC) {
            _api->UpdateGameObjectStateFromPhysicsTick(*gameObject);
        }
    }
}

void CollisionSystem::OnCloseEngine() {
    _debug.log("Collision system close"); // Empty
}
