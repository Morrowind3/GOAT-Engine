#include "PhysicsSystem.hpp"

using namespace Engine;

void PhysicsSystem::onLaunchEngine() {
    _debug.log("Physics system launch");
    _api = &PhysicsApi::getInstance();
}

void PhysicsSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Physics system load");
    _api->resetForNextScene();
    _scene = scene;
    unsigned int createdBodies = 0;
    for (auto& gameObject: _scene->gameObjects) {
        if(gameObject->rigidBody.active) {
            _api->createBody(*gameObject);
            ++createdBodies;
        }
    }
    _debug.log("Bodies created: " + std::to_string(createdBodies));
}

void PhysicsSystem::onFrameTick(const double deltaTime) {
    if (deltaTime == 0) return; // Increase performance by not calculating physics on pause
    _api->performPhysicsCalculationsForFrame();
    for (auto &gameObject: activeObjects()) {
        if (gameObject->rigidBody.active && gameObject->rigidBody.bodyType == BodyType::DYNAMIC) {
            _api->updateGameObjectStateFromPhysicsTick(*gameObject);
        }
    }
}

void PhysicsSystem::onCloseEngine() {
    _debug.log("Physics system close"); // Empty
}
