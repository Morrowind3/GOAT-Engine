#include "CollisionSystem.hpp"

using namespace Engine;

void CollisionSystem::onLaunchEngine() {
    _debug.log("Collision system launch");
    _api = &PhysicsApi::getInstance();
}

void CollisionSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Collision system load");
    _api->resetForNextScene();
    _scene = scene;
    for (auto& gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api->createBody(*gameObject);
        }
    }
}

void CollisionSystem::onFrameTick(double deltaTime) {
    _api->performPhysicsCalculationsForFrame();
    for (auto &gameObject: _scene->gameObjects) {
        if (gameObject->rigidBody.active && gameObject->rigidBody.bodyType == BodyType::DYNAMIC) {
            _api->updateGameObjectStateFromPhysicsTick(*gameObject);
        }
    }
}

void CollisionSystem::onCloseEngine() {
    _debug.log("Collision system close"); // Empty
}
