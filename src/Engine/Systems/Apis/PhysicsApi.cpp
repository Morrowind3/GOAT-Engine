#include "PhysicsApi.hpp"

using namespace Engine;

void PhysicsApi::CreateBody(const GameObject& gameObject)  {
    physics.CreateBody(gameObject);
}

void PhysicsApi::UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    physics.UpdateGameObjectStateFromPhysicsTick(gameObject);
}

void PhysicsApi::PerformPhysicsCalculationsForFrame() {
    physics.PerformPhysicsCalculationsForFrame();
}

void PhysicsApi::ResetForNextScene() {
    physics.ResetForNextScene();
}
