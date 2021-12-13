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
    int count = 0;
    for (auto& gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api->createBody(*gameObject);
            count++;
        }
    }

    std::cout << "Bodies created: " << count << std::endl;
}

void CollisionSystem::onFrameTick(const double deltaTime) {
    if (deltaTime == 0) return; // Increase performance by not calculating physics on pause
    _api->performPhysicsCalculationsForFrame(deltaTime);
    for (auto &gameObject: activeObjects()) {
        if (gameObject->rigidBody.active && gameObject->rigidBody.bodyType == BodyType::DYNAMIC) {
            _api->updateGameObjectStateFromPhysicsTick(*gameObject);
        }
    }
}

void CollisionSystem::onCloseEngine() {
    _debug.log("Collision system close"); // Empty
}
