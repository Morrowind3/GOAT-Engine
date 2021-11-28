#include "PhysicsApi.hpp"

using namespace Engine;

void PhysicsApi::createBody(const GameObject& gameObject)  {
    physics.createBody(gameObject);
}

void PhysicsApi::performPhysicsCalculationsForFrame() {
    physics.performPhysicsCalculationsForFrame();
}

void PhysicsApi::updateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    physics.updateGameObjectStateFromPhysicsTick(gameObject);
}

void PhysicsApi::runCollisionScripts() {
    physics.runCollisionScripts();
}

void PhysicsApi::resetForNextScene() {
    physics.resetForNextScene();
}


