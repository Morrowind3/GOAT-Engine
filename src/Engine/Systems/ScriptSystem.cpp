#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"

using namespace Engine;

ScriptSystem::ScriptSystem(const Scene* scene) : System(scene) {
}

void ScriptSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior->OnStart();
        }
    }
}

void ScriptSystem::OnUpdate(double deltaTime) {
    Input::GetInstance().Update();
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior->active) behavior->OnUpdate(deltaTime);
        }
    }
}

void ScriptSystem::OnDestroy() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior->OnDestroy();
        }
    }
}
