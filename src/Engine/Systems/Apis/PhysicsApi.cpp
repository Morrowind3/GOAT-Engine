#include "PhysicsApi.hpp"

using namespace Engine;

void PhysicsApi::CreateBody(const GameObject& gameObject)  {
    physics.CreateBody(gameObject);
}

void PhysicsApi::PerformPhysicsCalculationsForFrame() {
    physics.PerformPhysicsCalculationsForFrame();
}

void PhysicsApi::UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    physics.UpdateGameObjectStateFromPhysicsTick(gameObject);
}

void PhysicsApi::runCollisionScripts() {
    physics.runCollisionScripts();
}

void PhysicsApi::ResetForNextScene() {
    physics.ResetForNextScene();
}


